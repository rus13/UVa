#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int main() {
    int m,n;
    while(cin >> m >> n){
        //init
        long dp[m][n];
        int next[m][n];
        int matrix[m][n];
        int aux,cur;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        //base case
        for (int i = 0; i < m; i++) {
            dp[i][n-1] = matrix[i][n-1];
        }
        //dynamic programming
        for (int j = n-2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                cur=INT_MAX;
                for(int k=-1;k<=1;k++) {
                    aux = (i + k + m) % m;
                    if(cur > dp[aux][j+1] || (cur == dp[aux][j+1] && next[i][j] > aux)){
                        cur = dp[aux][j+1];
                        next[i][j] = aux;
                    }
                }
                dp[i][j] = cur + matrix[i][j];
            }
        }
        //find the min value and the path
        int min = 0;
        for (int i = 0; i < m; i++) {
            if(dp[min][0] > dp[i][0]){
                min = i;
            }
        }
        //print
        int tmp = min;
        cout << tmp+1;
        for (int i = 0; i < n-1; i++) {
            tmp = next[tmp][i];
            cout << " " << tmp+1;
        }
        cout << endl;
        cout << dp[min][0] << endl;
    }
    return 0;
}
/*
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 8 6 4
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3
2 2
9 10 9 10
* */