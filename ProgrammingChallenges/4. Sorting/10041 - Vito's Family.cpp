//solved
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, r;
    cin >> t;
    while(t--){
        //input
        cin >> r;
        vector<int> s(r);
        for(int i = 0; i< r;i++){
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        //init
        int dist_sum = 0;
        for(int i = 0; i < r - 1; i++){
            int dist = s[i+1] - s[i];
            dist_sum += (r - 1 - i) * dist;
        }
        //iterate
        int best_dist_sum = dist_sum;
        for(int i = 1; i < r; i++){
            int dist = s[i] - s[i - 1];
            dist_sum += (i-1)*dist;
            dist_sum -= (r - 1 - i) * dist;
            best_dist_sum = min(best_dist_sum, dist_sum);
        }
        //print
        cout << best_dist_sum << endl;
    }
    return 0;
}
/*
2
2 2 4
3 2 4 6
* */