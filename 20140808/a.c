#include <stdio.h>
#include <string.h>
#define YES 1
#define NO 0
#define LIMIT 30

char r[LIMIT];
int r_idx;
int r_cnt;

// goal : 목표 승리수
// wcnt : 현재 승리횟수
// lcnt : 현재 패배횟수
// win : 이겼는지 졌는지 체크
int check(int goal, int wcnt, int lcnt, int win) {
    int i;
    // add route
    if(win) {
        r[r_idx++] = 'o';
    }
    else {
        r[r_idx++] = 'x';
    }
    // check status
    if(wcnt >= goal) {
//        printf("goal %d, wcnt %d, lcnt %d, win %d\n", goal, wcnt, lcnt, win);
        for(i=0;i<r_idx;i++) {
            putchar(r[i]);
        }
        putchar('\n');
        r_cnt++;
        return 0;
    }
    if(lcnt >= goal) {
        return 0;
    }
    check(goal, wcnt+1, lcnt, YES);
    r_idx--;
    check(goal, wcnt, lcnt+1, NO);
    r_idx--;
    return 0;
}

int main() 
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        memset(r, 0, sizeof(r));
        r_idx = 0;
        r_cnt = 0;

        int goal;
        scanf("%d", &goal);
        check(goal, 1,0,1);
        r_idx--;
        check(goal, 0,1,0);
        printf("total %d case(s)\n", r_cnt);
    }
    return 0;
}
