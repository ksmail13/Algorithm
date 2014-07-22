#include <stdio.h>
#define LIMIT 31

// store stones weight
int s[LIMIT] = {};
int scnt;

// answer count;
int acnt;

void scale(int index, int weight, int target) {
    if(index > scnt) return;
    if(weight>target) return;
    else if(weight == target) {
        acnt++;
        return;
    }
    scale(index+1, weight+s[index], target);
    scale(index+1, weight, target);
}

int main() {
    int i,j;
    int weight = 0;
    scanf("%d", &scnt);
    for(i=0;i<scnt;i++) {
        scanf("%d", &s[i]);
        weight += s[i];
    }

    if(weight % 2 != 0) {
        printf("impossible\n");
        return;
    }
    scale(0, 0, weight/2);

    if(!acnt)   printf("impossible\n");
    else        printf("%d\n", acnt);

    return 0;
}
