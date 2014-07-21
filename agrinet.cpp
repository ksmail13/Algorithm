/*
 * HW 2014 07 17
 * agrinet.cpp
 * find shortest cable using by mst
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define FARM_LIMIT 110
#define LIMIT 100000

using namespace std;

typedef struct edge{
    int len;
    int p1, p2;
}Edge;

int edgecmp(const void *data1, const void *data2);

int search(int m[FARM_LIMIT][FARM_LIMIT], int visit[FARM_LIMIT], int size, int node, int s);

int main() {
    int farm_cnt=0;
    int m[FARM_LIMIT][FARM_LIMIT] = {};
    int shortmap[FARM_LIMIT][FARM_LIMIT] = {};
    struct edge e[LIMIT] = {};
    int edge_cnt=0;
    int i,j, len=0, conn_cnt=0;
    
    // get map data form stdin
    scanf("%d", &farm_cnt);
    for(i=0;i<farm_cnt;i++) {
        for(j=0;j<farm_cnt;j++) {
            scanf("%d", &m[i][j]);
        }
    }
    
    // set edges
    for (i=0; i<farm_cnt; i++) {
        for (j=0; j<i; j++) {
            if(!m[i][j]) continue;
            
            e[edge_cnt].len = m[i][j];
            e[edge_cnt].p1 = i;
            e[edge_cnt++].p2 = j;
        }
    }
    
    // sort edges
    qsort(e, edge_cnt, sizeof(struct edge), edgecmp);
    
    
    // generate mst with dfs
    for(i=0;i<edge_cnt && conn_cnt<farm_cnt;i++) {
        Edge &temp = e[i];
        int visit[FARM_LIMIT] = {};
        if(search(shortmap, visit, farm_cnt, temp.p1, temp.p2) == 0) {
            shortmap[temp.p1][temp.p2] = temp.len;
            shortmap[temp.p2][temp.p1] = temp.len;
            conn_cnt++;
        }
    }
    
    // sum length
    for(i=0;i<farm_cnt;i++) {
        for(j=0;j<i;j++) {
            len += shortmap[i][j];
        }
    }
    
    printf("%d\n", len);
    
    return 0;
}


int edgecmp(const void *data1, const void *data2) {
    int result =0;
    Edge *e1 = (Edge *)data1;
    Edge *e2 = (Edge *)data2;
    
    result = e1->len - e2->len;
    if(!result) {
        result = e2->p1 - e1->p1;
        if(!result) {
            result = e1->p2 - e2->p2;
        }
    }
    
    return result;
}

int search(int m[FARM_LIMIT][FARM_LIMIT], int visit[FARM_LIMIT], int size, int node, int s) {
    if(!m) return 0;
    int i;
    for(i=0;i<size;i++) {
        if(visit[i]==0 && m[node][i]) {
            visit[i] = 1;
            if(i == s) return 1;
            else if(search(m, visit, size, i, s)) return 1;
        }
    }
    
    
    return 0;
}