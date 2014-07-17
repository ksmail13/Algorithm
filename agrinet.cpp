/*
 * HW 2014 07 17
 * agrinet.cpp
 * find shortest cable using by mst
 */
#include <iostream>
#include <cstdlib>
#define LIMIT 200
using namespace std;

typedef struct edge {
    int len;
    int p1, p2;
}Edge;

int edgecmp(const void *data1, const void *data2);
int dfs(int map[LIMIT][LIMIT], int size, int start_point int search);

int main(int argc, char *argv[]) {
    int map[LIMIT][LIMIT] = {};
    int visit[LIMIT] = {};
    Edge edge_arr[LIMIT] = {};
    int edge_idx = 0;
    int min, minidx;
    int curr=1;
    
    int house_cnt, start_point;
    for(int i=0;i<house_cnt;i++)
        for(int j=0;j<house_cnt;j++)
            cin >> map[i][j];

	for(int i=1;i<houst_cnt;i++) {
		for(int j=1;j<i;j++) {
			edge_arr[edge_idx].len = map[i][j];
			edge_arr[edge_idx].p1 = i;
			edge_arr[edge_idx++].p2 = j;
            map[i][j] = 0;
		}
	}

	qsort((void *)edge_arr, edge_idx, sizeof(Edge), edgecmp);

    for(int i=0;i<edge_idx;i++) {
        Edge temp = edge_arr[edge_idx];
        int srch_pnt = temp.p1;
        int pass = 0;
        
        for(int j=0;j<house_cnt;j++) {
            int k = j;
            while(map[srch_pnt][k]) {
                if(j == temp.p2) {
                    pass = 1;
                    break;
                }
                else {
                    srch_pnt = k;
                    
                }
            }
        }
    }

	return 0;
}

int dfs(int map[LIMIT][LIMIT], int size, int start_point int search) {
    if(map) {
        int i, result = 0;
        for(i=0;i<size;i++) {
            if(map[start_point][i] && i==search ) {
                if(result = dfs(map, size, i, search)) {
                    return result;
                }
            }
        }
        
        return 0;
    }
    
    return 0;
} 


int edgecmp(const void *data1, const void *data2) {
	Edge *e1 = (Edge *)data1;
	Edge *e2 = (Edge *)data2;

	return e1.len - e2.len;
}
