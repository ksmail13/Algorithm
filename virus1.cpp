#include <iostream>
#define LIMIT 1000
using namespace std;

typedef void (*Work)(int);

void depth_first_search(int map[LIMIT][LIMIT], int *visit, int size, int curr, Work work);
void count_pc(int com_num);

int main(int argc, char *argv[]) {
    int map[LIMIT][LIMIT] = {};
    int visit[LIMIT] = {};
    int com_cnt;
    int couple_cnt;
    cin >> com_cnt >> couple_cnt;
    
    while(couple_cnt--) {
        int i, j;
        cin >> i >> j;
        
        map[i][j] = 1;
        map[j][i] = 1;
    }
    
    depth_first_search(map, visit, com_cnt+1, 1, count_pc);
    count_pc(0);
    
    return 0;
}


void depth_first_search(int map[LIMIT][LIMIT], int *visit, int size, int curr, Work work) {
    if(!map || visit[curr]) return;
    //cout << "DFS curr:" << curr << endl;
    int i=0;
    visit[curr] = 1;
    work(curr);
    for(i=0;i<size;i++) {
        if(map[curr][i]){
            
            depth_first_search(map,visit, size, i, work);
        }
    }
}

void count_pc(int com_num) {
    static int cnt=0;
    if(com_num) {
        cnt++;
    }
    else {
        cout << cnt-1<< endl;
    }
}