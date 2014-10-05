#include <stdio.h>
#define LIMIT 10000
int map[LIMIT][LIMIT] = {};
int main() {
    int n, m;
    int i, j, k, l;
    int sum=0;
    scanf("%d %d", &n, &m);

    for(i=0;i<m;i++) {
        int ai, aj;
        scanf("%d%d", &ai, &aj);
        map[ai-1][aj-1] = 1;
        map[aj-1][ai-1] = 1;
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            for(k=0;k<n;k++) {
                //rmap[i][j] += map[i][k]*map[k][j];
               sum += map[i][k]*map[k][j];          
            }
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
