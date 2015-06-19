#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int step, r, c, x;
    while (cin >> step, step-- != 0) {
        x = (int)sqrt(step);
        step -= x*x;
        r = c = x;
        if(step <= x){
            c = step;
        }
        else{
            r = 2*x - step;
        }
        if(x % 2 == 0){
            swap(r,c);
        }
        //print
        cout << (c+1) << " " << (r+1) << endl;
    }
    return 0;
}
/*
8
20
25
0
* */