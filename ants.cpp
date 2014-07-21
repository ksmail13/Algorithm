//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 2000000

#define MAX(x1, x2) ((x1) > (x2) ? (x1) : (x2))

//using namespace std;

int main() {
    int testcase;
    scanf("%d", &testcase);
    
    long long max=0, min = 0;
    
    while(testcase--) {
        long long len, ant_cnt;
        long long half;
        scanf("%lld %lld", &len, &ant_cnt);
        half = len/2;
        for(long long i=0;i<ant_cnt;i++) {
            long long temp, t2;
            long long temp_max, temp_min;
            scanf("%lld", &temp);
            
            //max
            temp_max = len-temp;
            //min
            temp_min = temp;
            
            if(temp_max < temp_min) {
                t2 = temp_max;
                temp_max = temp_min;
                temp_min = t2;
            }
            
            max = MAX(max, temp_max);
            min = MAX(min, temp_min);
            
        }
        printf("%lld %lld\n", min, max);
    }
    
    
    return 0;
}