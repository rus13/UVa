#include <iostream>
#include <algorithm>

using namespace std;

int t, n, k, tmp;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n;
        vector<vector<int>> bigraph(n, vector<int>(n, 0));
        vector<int> mr, mc;
        int edges = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            edges += k;
            for(int j = 0; j < k; j++){
                cin >> tmp;
                bigraph[i][tmp] = true;
            }
        }
        int match = BipartiteMatching(bigraph, mr, mc);
        cout << "Case #" << tc+1 << ": " << n - match<< endl;
    }
    return 0;
}