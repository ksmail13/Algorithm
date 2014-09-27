#include <iostream>
#include <cstdio>
using namespace std;
double balance(double n, double m, double p, double c) {
    double temp = n;
    //printf("n %lf m %lf p %lf c %lf\n", temp, m, p, c);
    for(int i=0;i<m;i++) {
        temp *= (1+p/1200.0);
        temp -= c;
    }
    //printf("result %lf\n", temp);
    return temp;
}

double find(double n, double m, double p)
{
    double low = n/m, high = n*(1+p/1200.0), mid;
    double res = 0.0;
    for(int i=0;i<=101;i++) {
        mid = (low+high)/2.0;
        res = balance(n, m, p, mid); 
        if(res > 0) {
            low = mid;
        }
        else if(res<0){
            high = mid;
        }
        else {
            return mid;
        }

        //printf("curr mid:%lf res:%lf\n", mid, res);
    }
    
    return mid;
}


int main() {
    int tcase;
    cin >> tcase;

    while(tcase--) {
        double n, m, p;
        cin >> n >> m >> p;
        printf("%lf\n", find(n,m,p));
        //cout << find(n, m, p) << endl;
    }

    return 0;
}
