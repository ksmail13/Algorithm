#include <iostream>

#define SWAP(a,b, t) ((t)=(a), (a)=(b), (b)=(t))

using namespace std;
int main() {
    int test_case;
    cin >> test_case;
    while(test_case--) {
        long long a, b, t;
        long long sa, sb;
        cin >> a >> b;
        sa = a;
        sb = b;
        
        if(b>a)
            SWAP(a,b,t);
        
        while(1) {
            
            t = a%b;
            //cout << a <<" "<< b<<" " << t << endl;
            if(t==0) {
               break; 
            }
            
            a = b;
            b = t;
        }
        t = sa*sb;
        if(t < 0) t -= -1;
        cout << b << " " << sa/b*sb << endl;
    }
    return 0;
}