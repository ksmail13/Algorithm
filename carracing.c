#include <stdio.h>

#define LIMIT 1000

int main(int argc, char *argv[]) {
    int i=0;
    int carcnt, currcar = 1;
    int car;
    int curcuit[LIMIT] = {};
    int curcuitcnt=0;
    scanf("%d", &carcnt);
    
    for(i=0;i<carcnt;i++) {
        scanf("%d", &car);
        if(car != currcar) {
            // 우회로에 차가 없는 경우
            if(curcuitcnt == 0)
                curcuit[curcuitcnt++] = car;
            else if(curcuit[curcuitcnt-1] > car) {
                printf("NO");
                return 0;
            }
        }
        else {
            currcar++;
        }
    }
    
    printf("YES");
    
    return 0;
}