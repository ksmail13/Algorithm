#include <stdio.h>
#define LIMIT 200

int map[LIMIT][LIMIT];
int visit[LIMIT];
int route[LIMIT];

int dfs(int curr, int nodecnt) {
    int i;
    if(visit[curr]) return 0;
    for(i=0;i<nodecnt;i++) {
        if(map[curr][i]) {
            visit[i] = 1;
            dfs(i, nodecnt);
            printf("%d ", i);
        }
    }

    return 0;
}

int main() {   
    int ecnt, vcnt;
    int i,j;
    int p1, p2;
    scanf("%d %d", &vcnt, &ecnt);

    for(i=0;i<ecnt;i++) {
        scanf("%d %d", &p1, &p2);

        map[p1][p2] = 1;
        map[p2][p1] = 1;
    }

    for(i=0;i<

    return 0;
}
