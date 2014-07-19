/*
 * HW 2014 07 17
 * agrinet.cpp
 * find shortest cable using by mst
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define LIMIT 1000
#define EDGE_LIMIT 100000
using namespace std;

typedef struct edge {
    int len;
    int p1, p2;
}Edge;

int edgecmp(const void *data1, const void *data2);
int bfs(int map[LIMIT][LIMIT], int size, int start_point, int search);

void print_map(int map[LIMIT][LIMIT], int size);

int main(int argc, char *argv[]) {
    int map[LIMIT][LIMIT] = {};
	//int netmap[LIMIT][LIMIT] = {};
    //int visit[EDGE_LIMIT] = {};
    Edge edge_arr[LIMIT] = {};
    int edge_idx = 0;
    int len = 0;
    
    int house_cnt;
    
    cin >> house_cnt;
    
    // get graph data from stdin
    for(int i=0;i<house_cnt;i++)
        for(int j=0;j<house_cnt;j++)
            cin >> map[i][j];
    
    // make edge set
    for(int i=0;i<house_cnt;i++) {
        for(int j=0;j<i;j++) {
            edge_arr[edge_idx].len = map[i][j];
            edge_arr[edge_idx].p1 = i;
            edge_arr[edge_idx++].p2 = j;
			map[i][j] = 0;
			map[j][i] = 0;
        }
    }
    
    //memset(map, 0, sizeof(map));
    
    // sorting for use Kruskal's algorithm
    qsort((void *)edge_arr, edge_idx, sizeof(Edge), edgecmp);
    
    
    // connect vertex
    for(int i=0;i<edge_idx;i++) {
        //        cout << "len " << edge_arr[i].len << " p1 " << edge_arr[i].p1 << " p2 " << edge_arr[i].p2 << endl;
        Edge &temp = edge_arr[i];
        int result;
        // check cycle
        if(!(result = bfs(map, house_cnt, temp.p1, temp.p2))) {
            map[temp.p1][temp.p2] = temp.len;

            map[temp.p2][temp.p1] = temp.len;
			cout << "i " << temp.p1 <<" j " << temp.p2 << " length " <<temp.len << " \nresult-------------------"  << endl;
//			print_map(map, house_cnt);
        }
        //cout << "search " << temp.p2 << " result " << result << endl;
    }
    
    // get cable length
    for(int i=0;i<house_cnt;i++) {
        for(int j=0;j<i;j++) {
            if(map[i][j]) {
//				cout<<"i" << i << "j" <<j << endl;
                len += map[i][j];
			}
        }
    }
    //print_map(map, house_cnt);
    cout << len << endl;
    
    return 0;
}

int bfs(int map[LIMIT][LIMIT], int size, int start_point, int search) {
    if(map) {
		int visit[LIMIT]={};
        int q[EDGE_LIMIT];
        int head=0, rear=0;
//        cout << "start point "<< start_point << " search point " << search << endl;
        q[rear++] = start_point;
        visit[start_point] = 1;
        
        while(head < rear) {
            int node;
            node = q[head++];
            
            for(int i=0;i<size;i++) {
//				cout << "node " << node<< " i " << i << " len " << map[node][i] <<endl;

                if(map[node][i] && i == search) {
                    return 1;
                }
				else if(map[node][i] && visit[i] == 0) {
                    visit[i] = 1;
                    q[rear++] = i;
				}
            }
        }
        
        return 0;
    }
    
    return 1;
}


int edgecmp(const void *data1, const void *data2) {
    Edge *e1 = (Edge *)data1;
    Edge *e2 = (Edge *)data2;
    
    return e1->len - e2->len;
}


void print_map(int map[LIMIT][LIMIT], int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            printf("%6d ", map[i][j]);
        }
        putchar('\n');
    }
}
