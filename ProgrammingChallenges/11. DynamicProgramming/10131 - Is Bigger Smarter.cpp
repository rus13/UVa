#include <iostream>
#include <vector>
#include <algorithm>
//solved
using namespace std;
struct elephant {
    int size;
    int iq;
    int id;
};

bool comp (elephant i,elephant j) { return (i.iq > j.iq); }

int main() {

    vector<elephant> el;
    int count = 1;
    while(!cin.eof()){
        elephant tmp;
        cin >> tmp.size;
        cin >> tmp.iq;
        tmp.id = count;
        el.push_back(tmp);
        count++;
    }
    sort(el.begin(),el.end(),comp);
    int n = el.size();
    int dp[n];
    int path[n];
    for(int i=0;i<n;i++){
        dp[i] = 1;
        path[i] = i;
        for(int j=0;j<i;j++){
            if(el[i].size > el[j].size && el[i].iq < el[j].iq){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    path[i] = j;
                }
            }
        }
    }
    int max = 0;
    for(int i=0;i<n;i++){
        if(dp[i] > dp[max]){
            max = i;
        }
    }
    cout<<dp[max]<<endl;
    int p[dp[max]];
    int tmp = max;
    for(int i=dp[max]-1;i>=0;i--){
        p[i]= el[tmp].id;
        tmp = path[tmp];
    }
    for(int i: p){
        cout<<i<<endl;
    }
    return 0;
}
/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
* */
