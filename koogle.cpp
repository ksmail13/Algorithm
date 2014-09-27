#include <iostream>
#include <cstdio>
#define LIMIT 1000

using namespace std;

int main() {
    int tcase;
    cin >> tcase;

    while(tcase--) {
        int n;
        cin >> n;
        string strongest= "";
        int str_lev = 0;
        for(int i=0;i<n;i++) {
            string temp;
            int level = 0;
            cin >> temp;

            for(int j=0;j<temp.length();j++) {
                if(temp[j] >= '0' && temp[j] <= '9')
                    level ++;
                else if(temp[j] >= 'a' && temp[j] <= 'z')
                    level +=2;
            }
           // printf("str_lev=%d level=%d isempty=%d compare=%d\n", str_lev, level, strongest.empty(), strongest.compare(temp));
            if(str_lev<=level && ( strongest.empty() || strongest.compare(temp) > 0)) {
                str_lev = level;
                strongest = temp;
            }
        }
        cout << strongest << endl;
    }

    return 0;
}
