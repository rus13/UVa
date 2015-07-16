#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    double a;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> a;
        cin >> n;
        vector<long long> x(n), y(n);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        }
        long long area = 0;
        for(int i = 0; i < n; i++){
            area += x[i]*y[(i+1)%n] - x[(i+1)%n]*y[i];
        }
        area = abs(area);
        long long cut = 0;
        for(int i = 0; i < n; i++){
            cut += abs(x[i]*y[(i+1)%n] - x[(i+1)%n]*y[i] + x[(i+1)%n]*y[(i+2)%n] - x[(i+2)%n]*y[(i+1)%n] + x[(i+2)%n]*y[i] - x[i]*y[(i+2)%n]);
        }
        cout << "Case #" << tc+1 << ": " << sqrt(cut /(area*(1.0-a))) << endl;
    }
    return 0;
}