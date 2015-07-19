#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int t, g, c, n;
    cin >> t;
    int max_coins = 10000 + 1;
    for(int tc = 0; tc < t; tc++){
        cin >> g >> c >> n;
        int p[n], s[n];
        string round_type[n];
        for(int i = 0; i< n;i++){
            cin >> round_type[i] >> p[i] >> s[i];
        }
        int dp[n+1][c+1][max_coins];
        memset(dp,-1,sizeof(dp));
        dp[0][c][0] = 0;
        //dp
        for(int i = 0;i < n;i++){
            for(int j = 0; j<=c; j++){
                for(int k = 0; k < max_coins; k++){
                    if(dp[i][j][k] >= 0){
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                        if( k >= s[i]){//silver
                            dp[i+1][j][k - s[i]] = max(dp[i+1][j][k - s[i]], 1 + dp[i][j][k]);
                        }
                        if(j > 0 && (round_type[i]!= "generous" || k < s[i] || s[i] == g)){ //gold
                            int change = 0;
                            if(round_type[i] == "generous")     change = ((g - s[i]+p[i]-1)/p[i]) * p[i];
                            else if(round_type[i] == "honest")  change = ((g - s[i]+p[i]/2)/p[i]) * p[i];
                            else if(round_type[i] == "greedy")  change = ((g - s[i])/p[i]) * p[i];
                            dp[i+1][j-1][k + change] = max(dp[i+1][j-1][k + change], 1 + dp[i][j][k]);
                        }
                    }
                }
            }
        }
        int m = 0;
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k < max_coins; k++) {
                m = max(m, dp[n][j][k]);
            }
        }
        cout << "Case #" << tc+1 << ": " << m << endl;
    }
    return 0;
}