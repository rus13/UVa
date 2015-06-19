#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647

using namespace std;
struct turtle{
    int w;
    int s;
};
bool comp (turtle i,turtle j) {
    if(i.s != j.s) return (i.s < j.s);
    else return (i.w > j.w);
}
int main() {
    //input
    int w, s;
    vector<turtle> t;
    //t.push_back(turtle{0,0});
    while(cin >> w >> s){
        if(s >= w){
            t.push_back(turtle{w,s});
        }
    }
    //init
    sort(t.begin(),t.end(),comp);
    int dp[t.size()+1];
    //base
    dp[0] = 0;
    dp[1] = t[0].w;
    for(int i = 2; i < t.size()+1; i++){
        dp[i] = INF;
    }
    //dp
    for(int i = 1; i < t.size(); i++){
        for(int k = t.size(); k >= 0; k--){
            if((dp[k - 1] < INF) && (dp[k - 1] + t[i].w <= t[i].s)){
                dp[k] = min(dp[k], dp[k - 1] + t[i].w);
            }
        }
    }
    //print
    int m = 0;
    for (int i = 0; i < t.size()+1; i++) {
        if(dp[i] < INF) m = max(m, i);
    }
    cout << m << endl;
    return 0;
}
/*
300 1000
1000 1200
200 600
100 101

 850 1650
 750 1600
 350 1200
 150 900
 350 400
*/