#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#define LIMIT 10000001
using namespace std;

int minFactor[LIMIT];
int minFactorPower[LIMIT];
int factor[LIMIT];


void eratosthenes() {
    int limit = int(sqrt(LIMIT));
    for(int i=0;i<LIMIT;i++) {
        minFactor[i] = i;
    }

    for(int i=2;i<limit;i++) {
        if(minFactor[i] == i) {
            for(int j=i*i;j<LIMIT;j+=i) {
                if(minFactor[j] == j) {
                    minFactor[j] = i;
                }
            }
        }
    }
}
/*
int factor(int n) {
    map<int, int> m;
    int result = 1;
    while(n>1) {
        m[minFactor[n]] = m[minFactor[n]] + 1;
        //printf("n %d minFactor[%d] %d\n", n,n,minFactor[n]);
//        result.push_back(minFactor[n]);
        n /= minFactor[n];
        
    }

    for(map<int, int>::iterator it = m.begin(); it!=m.end(); ++it) {
        result *= (it->second+1);
    }
    return result;
}


int main() {
    int tcase;
    eratosthenes();
    cin >> tcase;
    while(tcase--) {
        int n, low, high;
        int res_cnt=0;
        cin >> n >> low >> high;

        for(int i=low;i<=high;i++) {
            int f = factor(i);
            if(f==n)
                res_cnt++;
        }

        cout << res_cnt << endl;
    }
    return 0;
}
*/

int factorcount() {
    factor[1] = 1;
    for(int i=2;i<LIMIT;i++) {
        // 소수면 2
        if(minFactor[i] == i) {
            minFactorPower[i] = 1;
            factor[i]=2;
        }
        else {
            int p = minFactor[i];
            int m = i/p;

            if(p!=minFactor[m]) {
                minFactorPower[i] = 1;
            }
            else {
                minFactorPower[i] = minFactorPower[m]+1;
            }

            int a = minFactorPower[i];
            factor[i] = (factor[m]/a) * (a+1);
            //if(factor[i] == 0) {
            //    printf("n=%d minFactor[m=%d]=%d minFactorPower[m=%d]=%d factor[m=%d]=%d a=%d \n",i, m, minFactor[m], m, minFactorPower[m],m, factor[m], a); 
            }
        }
    }

}

int main() {
    eratosthenes();
    factorcount();
    int tcase;
    cin >> tcase;
    while(tcase--) {
        int n, low, high;
        int res_cnt=0;
        cin >> n >> low >> high;

        for(int i=low;i<=high;i++) {
            if(factor[i] == n)
                res_cnt++;
        }

        cout << res_cnt << endl;
    }
    return 0;
}
