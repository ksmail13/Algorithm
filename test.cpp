#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> data;
    data.push_back(1);
    data.push_back(4);
    data.push_back(3);
    data.push_back(5);

    sort(data.begin(), data.end());

    do{ 
        for(int i=0;i<data.size();i++) {
            cout << data[i];
        }
        cout << endl;
    }while(next_permutation(data.begin(), data.end()));

    return 0;
}   
