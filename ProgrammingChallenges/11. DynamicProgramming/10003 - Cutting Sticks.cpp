//solved
#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647

using namespace std;

int main() {
    int l = 0;
    while(true){
        cin >> l;
        if(l == 0) break;
        //input
        int n;
        cin >> n;
        n += 2;
        int cut[n];
        cut[0] = 0;
        cut[n-1] = l;
        for(int i = 1; i < n - 1; i++){
            cin >> cut[i];
        }
        //base
        int dp[n][n];
        for(int i = 0; i < n; i++){
            dp[i][i+1] = 0;
        }
        //dp
        for (int step = 2; step < n; step ++){
            for(int i = 0; i + step < n; i++){
                int j = i + step;
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                dp[i][j] += cut[j] - cut[i];
            }
        }
        //print
        cout << "The minimum cutting is " << dp[0][n-1] << "." << endl;
    }
    return 0;
}
/*
100
3
25 50 75
10
4
4 5 7 8
0
* */