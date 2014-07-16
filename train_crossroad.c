#include <stdio.h>

#define LIMIT 10000
int main(int argc, char *argv[]) {
    int traincnt=0;
    int train, crossroad[LIMIT];
    int crossroadcnt=0;
    char workhistory[LIMIT];
    int historycnt=0;
    int currtrain=1;
    int i;
    
    scanf("%d", &traincnt);
    for(i=0;i<traincnt;i++) {
        scanf("%d", &train);
        
        crossroad[crossroadcnt++] = train;
        workhistory[historycnt++] = 'S';
        
        // train top이 필요한 기차면 pop
        if(currtrain == crossroad[crossroadcnt-1])
        {
            workhistory[historycnt++] = 'X';
            crossroadcnt--;
            currtrain++;
        }
    }
    
    while(crossroadcnt) {
        if(crossroad[--crossroadcnt] == currtrain) {
            currtrain++;
            workhistory[historycnt++] = 'X';
        }
        else {
            printf("NO");
            return 0;
        }
    }
    workhistory[historycnt] = '\0';
    
    printf("%s", workhistory);
    return 0;
}