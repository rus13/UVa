//solved
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        vector<int> stack;
        int tmp;
        while(ss >> tmp){
            stack.push_back(tmp);
            cout << tmp << " " ;
        }
        cout << endl;
        std::reverse(stack.begin(), stack.end());
        for(int i = 0; i < stack.size(); i++){
            auto it = std::max_element(stack.begin()+i, stack.end());
            int dist = it - (stack.begin()+i);
            if(dist > 0){
                if(it != stack.end()-1){
                    cout << (dist + i + 1) << " " ;
                    std::reverse(it, stack.end());
                }
                cout << (i + 1) << " " ;
                std::reverse(stack.begin()+i, stack.end());
            }
        }
        cout << 0 << endl;
    }
    return 0;
}
/*
1 2 3 4 5
5 4 3 2 1
5 1 2 3 4
* */