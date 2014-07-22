#include <stdio.h>
#define VERTEX_MAX 32
#define BLOCK 1000

#define MIN(x,y) ((x) > (y) ? (x) : (y)) 

int map[VERTEX_MAX][VERTEX_MAX];
int dmap[VERTEX_MAX][VERTEX_MAX];
int main() {
    int ecnt, start, end;
    int i,j,k;

    scanf("%d %d %d", &ecnt, &start, &end);
    for(i=1;i<=ecnt;i++) {
        for(j=1;j<=ecnt;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    
    for(i=1;i<=ecnt;i++) {
        for(j=1;j<=ecnt;j++) {
            printf("%4d ", map[i][j]);
        }
        putchar('\n');
    }

    for(i=1;i<=ecnt;i++) {
        for(j=1;j<=ecnt;j++) {
            if(map[i][j] > 0 && map[i][j] != BLOCK)
                dmap[i][j] = map[i][j];
            else
                dmap[i][j] = 0x0FFFFFFF;
        }
    }

    for(k=1;k<=ecnt;k++) {
        for(i=1;i<=ecnt;i++) {
            for(j=1;j<=ecnt;j++) {
                if(dmap[i][j] > dmap[i][k] + dmap[k][j])
                    dmap[i][j] = dmap[i][k] + dmap[k][j];
            }
        }
    }
    
    for(i=1;i<=ecnt;i++) {
        for(j=1;j<=ecnt;j++) {
            printf("%d ", dmap[i][j]);
        }
        putchar('\n');
    }

    printf("%d\n", dmap[start][end]);
    return 0;
}
