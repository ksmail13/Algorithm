#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
/*
int main() {
    int tcase;
    cin >> tcase;
    while(tcase--) {
        double n, m;
        cin >> n  >> m;
        if(n==m) {
            printf("-1\n");
            continue;
        }
        double g = (m/n*100.0+1.0);
        //printf("%lf/%lf = %lf g %lf\n", m, n, m/n, g);
        if(g >= 99.0) {
            printf("-1\n");
            continue;
        }
        long long c = (long long)ceil(abs((n/(100-g))*g)-(m/(100-g))*100);
        printf("%lld\n", c<0?-1:c);

    }

    return 0;
}*/

long long L = 2000000000;

int ratio(long long b, long long a) {
    return a*100/b;
}

int needgame(long long games, long long won) {

    if(ratio(games, won) == ratio(games + L, won+L))
        return -1;

    long long lo = 0, hi = L;


    while(lo+1 < hi) {
        long long mid = (lo+hi)/2;
        if(ratio(games, won) == ratio(games + mid, won+mid))
        {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    return hi;
}


int main() {
    int tcase;
    cin >> tcase;
    while(tcase--) {
        long long m, n;

        cin >> m >> n;
        printf("%d\n", needgame(m, n));
    }
    return 0;
}
