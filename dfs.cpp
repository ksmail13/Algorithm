#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LIMIT 10

typedef int datatype;

int map[LIMIT][LIMIT]={};
int visit[LIMIT];

typedef void (*Work)(datatype);

void depth_first_search(int arr[LIMIT][LIMIT], int size, datatype curr, Work work);
void breath_first_search(int arr[LIMIT][LIMIT], int size, datatype curr, Work work);
void print_vertex(datatype d);

void print_map(int arr[LIMIT][LIMIT], int size);

using namespace std;

int main(int argc, char *argv[]) {
    int point=1, before=-1;
    int max=0;
    while(1) {
        cin >> point;
        if(!point) break;
        
        if(max < point)max = point;
        
        if(before != -1) {
            map[point][before] = 1;
            map[before][point] = 1;
            before = -1;
        }
        else before = point;
    }
    
    //print_map(map, max+1);
    
    //cout << max << endl;
    
    depth_first_search(map, max+1, 1, print_vertex);
    putchar('\n');
    memset(visit, 0, sizeof(visit));
    breath_first_search(map, max+1, 1, print_vertex);
    putchar('\n');
    
    return 0;
}

void depth_first_search(int map[LIMIT][LIMIT], int size, datatype curr, Work work) {
    if(!map || visit[curr]) return;
    //cout << "DFS curr:" << curr << endl;
    int i=0;
    visit[curr] = 1;
    work(curr);
    for(i=0;i<size;i++) {
        if(map[curr][i]){
            
            depth_first_search(map, size, i, work);
        }
    }
}

void breath_first_search(int arr[LIMIT][LIMIT], int size, datatype curr, Work work) {
    if(!map || visit[curr]) return;
    //cout << "DFS curr:" << curr << endl;
    datatype q[LIMIT];
    int start=0, end=0;
    int i=0;
    visit[curr] = 1;
    work(curr);
    q[end++] = curr;
    while(start < end) {
        int chk = q[start++];
        for(i=0;i<size;i++){
            if(map[chk][i] && !visit[i]){
                visit[i] = 1;
                q[end++] = i;
                work(i);
            }
        }
    }
}

void print_map(int arr[LIMIT][LIMIT], int size) {
    cout << size << endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            printf("%d ", arr[i][j]);
        putchar('\n');
    }
}

void print_vertex(datatype d) {
    cout << d << " ";
}