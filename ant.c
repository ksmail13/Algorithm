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
    while(testcase--) {
        clock_t start = clock();
        long long len, ant_cnt;
        int half;
        int ant_point[LIMIT] = {};
        
        long long max=0, min = 0, min_idx;
        int maxfix=0, minfix=0;
//        cin >> len >> ant_cnt;
        scanf("%lld %lld", &len, &ant_cnt);
        half = len/2;
        
        for(long long i=0;i<ant_cnt;i++) {
            int temp, t2;
            int temp_max, temp_min;
//            cin >> temp;
//            scanf("%d", &temp);
            temp = rand()%len;
            //printf("%d \t", temp);
            ant_point[i] = temp;
            //if(temp == max || ant_point[min_idx] == temp || (maxfix && minfix)) continue;
            
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
            /*
            //max
            if(temp < half) {
//                max = MAX(max, len-temp);
                if(max < len-temp)
                    max = len-temp;
                if(len-temp == 0) maxfix = 1;
            }
            else {
                if(max < temp)
                    max = temp;
//                max = MAX(max, temp);
                if(temp == len) maxfix = 1;
            }
            
            t2 = half-temp;
            if(t2 < 0) t2 *= -1;
            //min
            if(min > t2) {
                //cout << min << " " << half << " " << temp << " " << i << endl;
                min_idx = i;
                min = t2;
                if(min == 0)
                    minfix = 1;
            } 
            */
        }
        
//        if(ant_point[min_idx] > half) min = len-ant_point[min_idx];
//        else min = ant_point[min_idx];
        
        printf("%lld %lld\n", min, max);
        printf("%lf\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
        //cout <<min << " " << max << endl;
    }
    
    return 0;
}