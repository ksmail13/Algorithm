#include <stdio.h>
#define LIMIT 101

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main() {
    int m[LIMIT][LIMIT] = {};
    int i,j;
    int size;
    
    scanf("%d", &size);
    for(i=1;i<=size;i++) {
        for(j=1;j<=size;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for(i=1;i<=size;i++) {
        for(j=1;j<=size;j++) {
            m[i][j] = MAX(m[i-1][j], m[i][j-1]) + m[i][j];
        }
    }
    
    printf("%d\n", m[size][size]);
    return 0;
}
