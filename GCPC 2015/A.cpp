#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int INF = 1000000000;
typedef pair<int,int> PII;

int  N, P, M, G, T;
int dp[1<<17][17][2];
int dist[17][17];
int with_taxi, without_taxi;

vector<int> dijkstra(vector<vector<PII> > &edges, int s){
  size_t n = edges.size();
  // use priority queue in which top element has the "smallest" priority
  priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<int> dist(n, INF), dad(n, -1);
  Q.push (make_pair (0, s));
  dist[s] = 0;
  while (!Q.empty()){
    PII p = Q.top();
    Q.pop();
    int here = p.second;
    for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
      if (dist[here] + it->first < dist[it->second]){
        dist[it->second] = dist[here] + it->first;
        dad[it->second] = here;
        Q.push (make_pair (dist[it->second], it->second));
      }
    }
  }
  return dist;
}

void tsp_dp() {
  int i, j, k, p;
  memset(dp, -1, sizeof(dp));
  dp[1][0][0] = 0;
  // TSP solution here,bitmask and DP
  for (i = 1; i < (1 << P); i+=2) {// the current state
    for (j = 0; j < P; j++) {// during the current state,the last station is j
      for (int t = 0; t < 2; t++) {
        if (dp[i][j][t] == -1) continue;
        for (k = 1; k < P; k++) {//the next state is k
          if ((i & (1 << k)) == 0) {
            p = (i | (1 << k));// the new state(join k)
            dp[p][k][t] = (dp[p][k][t] == -1)? (dp[i][j][t] + dist[j][k]) : min(dp[p][k][t], dp[i][j][t] + dist[j][k]);//no taxi
            if (t == 0) dp[p][k][1] = (dp[p][k][1] == -1)? (dp[i][j][0] + T) : min(dp[p][k][1], dp[i][j][0] + T);//taxi
          }
        }
      }
    }
  }
  with_taxi = without_taxi = INF;
  // get answer
  for (i = 1; i < P; i++) {
    with_taxi = min(with_taxi, dp[(1 << P) - 1][i][1] + dist[i][0]);//taxi already used
    with_taxi = min(with_taxi, dp[(1 << P) - 1][i][0] + T);// use taxi
    without_taxi = min(without_taxi, dp[(1 << P) - 1][i][0] + dist[i][0]); //don't use taxi
  }
}

int main(){
  int count_tests, s, d, l, t, p;
  cin >> count_tests;
  for(int tc = 1; tc <= count_tests; tc++){
    cin >> N >> P >> M >> G >> T;
    vector<int> site(P+1, 0);
    vector<vector<PII> > edges(N);
    for(int i = 1; i <=P;i++){
      cin >> p >> t;
      site[i] = p;
      G -= t;
    }
    P++;
    for(int i = 0; i < M; i++){
      cin >> s >> d >> l;
      edges[s].push_back (make_pair (l, d));
      edges[d].push_back (make_pair (l, s));
    }
    for(int i = 0; i < site.size(); i++){
      vector<int> dd = dijkstra(edges, site[i]);
      for(int j = 0; j < site.size(); j++){
        dist[i][j] = dd[site[j]];
      }
    }
    tsp_dp();
    cout << "Case #" << tc << ": ";
    if(without_taxi <= G){
      cout << "possible without taxi" << endl;
    }
    else if(with_taxi <= G){
      cout << "possible with taxi" << endl;
    }
    else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}