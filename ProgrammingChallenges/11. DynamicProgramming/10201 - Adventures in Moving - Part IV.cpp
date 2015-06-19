#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

#define INF 2147483647
using namespace std;

struct station{
    int d;
    int p;
};
int main() {
    int t, d;
    char line[64];
    cin >> t;
    while (t--) {
        //input
        vector<station> st;
        cin >> d;
        cin.getline(line,64);
        while(cin.getline(line,64), strcmp(line,"")!=0){
            st.push_back(station{atoi(strtok(line, " ")),atoi(strtok(NULL, " "))});
        }
        //init
        st.push_back(station{d, 0});
        int dp[st.size()][201];
        //base
        for(int i=0;i<201;i++){
            dp[0][i] = INF;
        }
        if(st[0].d <= 100) dp[0][100-st[0].d] = 0;
        //dp
        for(int s = 1; s < st.size(); s++){
            for(int g = 0; g <201; g++){
                dp[s][g] = INF;
                int dist = st[s].d - st[s-1].d;
                for(int i=0;i<201;i++){
                    int gas = g - i + dist;
                    if( gas >=0 && i + gas <=200 && dp[s-1][i] < INF){
                        dp[s][g] = min(dp[s][g], dp[s-1][i] + gas*st[s-1].p );
                    }
                }
            }
        }
        //print
        if( dp[st.size()-1][100] < INF)
            cout << dp[st.size()-1][100] << endl;
        else cout << "Impossible" << endl;
        if(t>0) cout << endl; //important, else presentation error
    }
    return 0;
}
/*
2

500
100 999
150 888
200 777
300 999
400 1009
450 1019
500 1399

500
100 999
150 888
200 777
300 999
400 1009
450 1019
500 1399

* */