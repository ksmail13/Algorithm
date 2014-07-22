#include <stdio.h>

#define LIMIT 11
#define START 1
void dfs(int map[LIMIT][LIMIT], int visit[LIMIT], int index, int cnt);

int main() {
    int map[LIMIT][LIMIT] = {};
    int visit[LIMIT] = {};
    int i,j;
    int vcnt=0, start;
    scanf("%d %d", &vcnt, &start);
    while(scanf("%d %d", &i, &j) != EOF) {
        map[i][j] = 1;
        map[j][i] = 1;
    }

    dfs(map, visit, start, vcnt);
    putchar('\n');
    return 0;
}


void dfs(int map[LIMIT][LIMIT], int visit[LIMIT], int index, int cnt) {
    if(!map || !visit) return;
    int i;
    printf("%d ", index);
    visit[index] = 1;
    for(i=START;i<cnt;i++) {
        if(visit[i] == 0 && map[index][i]) {
            dfs(map, visit, i);
        }
    }
}
