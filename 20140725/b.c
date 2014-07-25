//#include <iostream>
#include <stdio.h>
#define LIMIT 3010
#define ABS(x) ((x) > 0 ? (x) : -1*(x))
int main() {
    int testcase;
    int i,j;
    scanf("%d", &testcase);
    while(testcase--) {
        int n;
//        long long check=0;
        int check[LIMIT] = {};
        long long t, bt=0;
        int fail=0;
        
        scanf("%d",&n);
        scanf("%lld", &t);
        for(i=1;i<n;i++) {
            bt = t;
            scanf("%lld", &t);
//            printf("check : %d diff : %d\n", check, t-bt); 
//            check += ABS(t-bt);
            if(check[ABS(t-bt)]) fail=1;            
            else check[ABS(t-bt)] = 1;
        }
        
        for(i=1;i<n-1 && !fail;i++) {
            if(!check[i]) fail = 1;
        }
//        printf("result check %d need %d\n", check, (n*(n-1))/2);
//        if(check != (n*(n-1))/2)
        if(fail)
            printf("Not jolly\n");
        else
            printf("Jolly\n");
    }
    return 0;
}
