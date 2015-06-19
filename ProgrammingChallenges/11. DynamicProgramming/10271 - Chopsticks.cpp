#include <iostream>
#include <vector>
#define INF 2147483647
using namespace std;

int main() {
    int t, k, n;
    cin >> t;
    while (t--) {
        //input
        cin >> k;
        cin >> n;
        k += 8;
        int len[n];
        for(int i=0;i<n;i++){
            cin >> len[i];
        }
        //init
        vector<int> dp(n, 0), prev(n);
        int bad[n-1];
        for(int i=0;i<n-1;i++){
            bad[i] = (len[i]-len[i+1])*(len[i]-len[i+1]);
        }
        //dp
        for(int p = 1; p < k+1; p++){
            prev.swap(dp);
            dp[n-1] = INF;
            dp[n-2] = INF;
            for(int c = n-3; c >=0; c--){
                dp[c] = dp[c+1];
                if((n -(c+2) > 3*(p-1)) && prev[c+2] < INF){
                    dp[c] = min(dp[c+1], prev[c+2] + bad[c]);
                }
            }
        }
        //print
        cout << dp[0] << endl;
    }
    return 0;
}
/*
1
1 40
1 8 10 16 19 22 27 33 36 40 47 52 56 61 63 71 72 75 81 81 84 88 96 98
103 110 113 118 124 128 129 134 134 139 148 157 157 160 162 164

* */