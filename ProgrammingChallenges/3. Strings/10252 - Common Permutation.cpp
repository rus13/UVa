#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    int i, j;
    while (getline(cin, a) && getline(cin,b)) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        i = j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                cout << a[i];
                i++;
                j++;
            }
            else  if (a[i] < b[j]){
                i++;
            }
            else j++;
        }
        cout << endl;
    }
    return 0;
}
/*
pretty
women
walking
down
the
street
* */