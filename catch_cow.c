#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 100000

int chk[LIMIT];

int search(int *q, int qlen, int level, int target);

int main(int argc, char *argv[]) {
    int n, k;
    int time=0;
    int *q=(int*) calloc(3, sizeof(int));
    scanf("%d %d", &n ,&k);
    if(k == n) {
        printf("0");
        return 0;
    }
    else if (k < n) {
        printf("%d", n-k);
        return 0;
    }
    
    q[0] = n+1;
    q[1] = n-1;
    q[2] = n*2;
    
    printf("%d", search(q, 3, 1, k));
    return 0;
}

int search(int *q, int qlen, int level, int target) {

    int *qchild=(int *)malloc(qlen*3*sizeof(int));
    int qchildlen=0;
    int result;
    int i;
    for(i=0;i<qlen;i++) {
        if(q[i] == target) return level;
        
        if(q[i] < LIMIT && chk[q[i]] == 0){
            chk[q[i]] = 1; 
            qchild[qchildlen++] = q[i]+1;
            qchild[qchildlen++] = q[i]-1;
            qchild[qchildlen++] = q[i]*2;
        }
    }
    free(q);
    result = search(qchild, qchildlen, level+1, target);

    return result;
}