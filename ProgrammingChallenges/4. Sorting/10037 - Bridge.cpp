#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int t, n, i;
    vector<int> a(1000);
    cin >> t;
    while(t--){
        cin >> n;
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.begin()+n);
        stringstream ss;
        int cost = 0;
        for(i = n-1; i > 2; i-=2){
            if(2 * a[1] < a[i-1] + a[0]){
                ss << a[0] << " " << a[1] << endl;
                ss << a[0] << endl;
                ss << a[i] << " " << a[i-1] << endl;
                ss << a[1] << endl;
                cost += a[i] + 2 * a[1] + a[0];
            }
            else{
                ss << a[0] << " " << a[i] << endl;
                ss << a[0] << endl;
                ss << a[0] << " " << a[i-1] << endl;
                ss << a[0] << endl;
                cost += a[i] + a[i-1] + 2 * a[0];
            }
        }
        if(i == 0){
            ss << a[0] << endl;
            cost += a[0];
        }
        else if(i == 1){
            ss << a[0] << " " << a[1] << endl;
            cost += a[1];
        }
        else if(i == 2){
            ss << a[0] << " " << a[1] << endl;
            ss << a[0] << endl;
            ss << a[0] << " " << a[2] << endl;
            cost += a[0] + a[1] + a[2];
        }
        cout << cost << endl;
        cout << ss.str();
        if(t) cout << endl;
    }
    return 0;
}