//todo
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int it=1;it<=t;it++){
        string sequence;
        cin >> sequence;
        string sub;
        cin >> sub;
        long long dp[sequence.length()][sub.length()];
        for(int i = 0;i<sub.length();i++){
            dp[0][i] = 0;
        }
        if(sequence[0] == sub[0]) {
            dp[0][0] = 1;
        }
        for(int i = 1;i<sequence.length();i++){
            if(sequence[i] == sub[0]) {
                dp[i][0] = dp[i-1][0] + 1;
            }
            else dp[i][0] = dp[i-1][0];
        }
        for(int j = 1;j<sub.length();j++){
            for(int i = 1;i<sequence.length();i++){
                dp[i][j] = dp[i-1][j];
                if(sequence[i] == sub[j]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        cout << dp[sequence.length()-1][sub.length()-1]<<endl;
    }
    return 0;
}
/*
2
babgbag
bag
rabbbit
rabbit
* */
