#include <stdio.h>
#define LIMIT 110

// graph array
int g[LIMIT][LIMIT];
// visited check array
int v[LIMIT][LIMIT];
// euler path
int route[LIMIT];
// index for save euler path
int r_idx;


// find euler path in g(graph)
// @param : vertex : current vertex name
//          v_cnt : number of vertex
//          e_cnt : number of edge
void get_euler_path(int vertex, int v_cnt, int e_cnt) { 
    int i,j;
    // TODO : get euler path using dfs
    //        check edge not vertex

}

int main() {
    int e_cnt, v_cnt;
    int i,j;
    scanf("%d%d", &e_cnt, &v_cnt);

    for(i=0;i<v_cnt;i++) {
        int from, to;
        scanf("%d%d", &from, &to);

        g[from][to] = 1;
        g[to][from] = 1;
    }

    for(i=1;i<v_cnt;i++) {
        for(j=1;j<v_cnt;j++) {
            visit[i][j] = 1;
            visit[j][i] = 1;

            if(g[i][j])
                get_euler_path(j, v_cnt, e_cnt);

            visit[i][j] = 0;
            visit[j][i] = 0;
        }

    }

    return 0;
}
