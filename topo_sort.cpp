#include <iostream>
#define LIMIT 110
using namespace std;

void topol_sort(int map[LIMIT][LIMIT], int size);

int main(int argc, char *argv[]) {
    int map[LIMIT][LIMIT];
    int p_cnt;
    cin>>p_cnt;
    while(1) {
        int i, j;
        cin >> i >> j;
        if(cin.fail()) break;
        map[i][j] = 1;
        if(map[j][i]) {
            cout << "impossible" << endl;
            return 0;
        }
            
    }
    
    topol_sort(map, p_cnt+1);
    return 0;
}

void topol_sort(int map[LIMIT][LIMIT], int size) {
    int visit[LIMIT] = {};
    int q[LIMIT] = {};
    int start=0, end=0, i, j, k;
    int res[LIMIT] = {};
    int res_idx = 0;
    
    q[end++] = 1;
    res[res_idx++] = 1;
    
    while(start < end) {
        int chk = q[start++];
        for(i=0;i<size;i++){
            if(chk == i) continue;
            if(map[chk][i] && !visit[i]){
                visit[i] = 1;
                q[end++] = i;
                
            }
        }
    }
    
    for(i=0;i<res_idx;i++) 
        cout << res[i] << " ";
}