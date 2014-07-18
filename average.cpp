#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int test_case;
    cin >> test_case;
    while(test_case--) {
        double d = 0.0;
        for(int i=0;i<4;i++) {
            int temp;
            //cin >> temp;
            scanf("%d", &temp);
            d += 1.0*temp;
        }
        
        printf("%.2lf\n", d/4.0);
    }
    return 0;
}