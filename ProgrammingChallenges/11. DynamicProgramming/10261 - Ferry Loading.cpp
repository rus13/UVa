//solved
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, ferry, tmp;
    cin >> t;
    while (t--) {
        //input
        vector<int> car(1, 0);
        vector<int> sum(1, 0);
        cin >> ferry;
        ferry *= 100;
        while (cin >> tmp, tmp > 0) {
            car.push_back(tmp);
            sum.push_back(sum[sum.size() - 1] + tmp);
        }
        //init
        vector<vector<int> > dp(car.size(), vector<int>(ferry + 1, -1));
        pair<int, int> last = make_pair(0, 0);
        //base
        dp[0][0] = 0;
        //dp
        for (int i = 0; i < car.size() - 1; i++) {
            for (int j = 0; j < ferry + 1; j++) {
                if (dp[i][j] != -1) {
                    if (j + car[i + 1] <= ferry) {
                        dp[i + 1][j + car[i + 1]] = 0;
                        last = make_pair(i + 1, j + car[i + 1]);
                    }
                    if (sum[i] - j + car[i + 1] <= ferry) {
                        dp[i + 1][j] = 1;
                        last = make_pair(i + 1, j);
                    }
                }
            }
        }
        //print
        int out[car.size()-1];
        int p = last.first;
        while (last.first > 0) {
            out[last.first - 1] = dp[last.first][last.second];
            if (dp[last.first][last.second] == 0) {
                last.second -= car[last.first];
            }
            last.first--;
        }
        cout << p << endl;
        for (int i = 0; i < p; i++) {
            if (out[i] == 0)
                cout << "starboard" << endl;
            else
                cout << "port" << endl;
        }
        if(t > 0) cout << endl;
    }
    return 0;
}
/*
3
50
2500
3000
1000
1000
1500
700
800
0
10
0

* */