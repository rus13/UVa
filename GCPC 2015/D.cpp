#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int t, W, H, c;
int w[7], h[7], a[7], sol[7];
bool cover[200][200];

pair<int,int> first_uncovered(){
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(!cover[i][j]) return make_pair(i, j);
        }
    }
    return make_pair(-1,-1);
}

bool is_candidate(int x, int y,int xdiff, int ydiff){
    if((x + xdiff > W ) || (y + ydiff > H )) return false;
    for(int i = x; i< x + xdiff; i++){
        for(int j = y; j < y + ydiff; j++){
            if(cover[i][j]) return false;
        }
    }
    return true;
}

void set_carpet(int x, int y, int xdiff, int ydiff, bool val){
    for(int i = x; i< x + xdiff; i++){
        for(int j = y; j < y + ydiff; j++){
            cover[i][j] = val;
        }
    }
}

bool bt(){
    pair<int,int> first = first_uncovered();
    if(first.first == -1) return true;
    int x = first.first, y =first.second;
    for(int i = 0; i < c; i++){
        if(sol[i] < a[i]){
            sol[i]++;
            for(int k = 0; k < 2; k++){
                swap(w[i], h[i]);
                if(is_candidate(x, y,w[i], h[i])){
                    set_carpet(x, y, w[i], h[i], true);
                    if(bt()) return true;
                    set_carpet(x, y,w[i], h[i], false);
                }
            }
            sol[i]--;
        }
    }
    return false;
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> W >> H >> c;
        for (int i = 0; i < c; i++) cin >> a[i] >> w[i] >> h[i];
        memset(cover,0, sizeof(cover));
        memset(sol,0, sizeof(sol));
        cout << "Case #" << tc+1 << ": ";
        if(bt()) cout << "yes" << endl;
        else cout << "no" << endl;

    }
    return 0;
}