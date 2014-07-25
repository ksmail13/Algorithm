#include <stdio.h>
#define LIMIT 200

int map[LIMIT][LIMIT];
int visit[LIMIT];
int route[LIMIT];
int r_idx;

/**
 * find way to euler path
 * check visited EDGE NOT VERTEX!!!!!!!!!!!!!!!!!
 * @param : curr current vertex name
 *          ecnt number of edge
 *          vcnt number of vertex
 * @return : is finish(meaningless)
 */
int dfs(int vcurr, int ecnt, int vcnt) {
    int i,j;
    for(i=0;i<ecnt;i++) {
        if(map[curr][i] && visit[i]==0) {
            visit[i] = 1;
            for(j=0;j<vcnt;j++) {
                if(j != curr && map[j][i]) {
                    dfs(j, ecnt, vcnt);
                    break;
                }
            }
            visit[i] = 0;
        }
    }

    return 0;
}

int main() {   
    int ecnt, vcnt;
    int i,j, k;
    int p1, p2;
    scanf("%d %d", &vcnt, &ecnt);

    // get data from standard input
    for(i=0;i<ecnt;i++) {
        scanf("%d %d", p1, p2);
        map[p1][i] = 1;
        map[p2][i] = 1;
    }

    // loop for vertex
    for(i=0;i<vcnt;i++) {
        //loop for edge
        for(j=0;j<ecnt;j++) {
            if(map[i][j]) {
                visit[j] = 1;
                for(k=0;k<vcnt;k++) {
                    if(k == i) continue;
                    dfs(k, ecnt, vcnt);
                }
                visit[j]=0;
            }
        }
    }

    return 0;
}
