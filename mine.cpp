#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LIMIT 100

#define MINE '*'
#define EMPTY '.'
#define CLICK 'x'

using namespace std;

char checkmine(char omap[LIMIT][LIMIT], int size, int i, int j);

int main() {
    int testcase;
    
    freopen("input.txt", "r", stdin);
    
    cin >> testcase;
    
    while(testcase--) {
        int size;
        int isMineClick = 0;
        cin >> size;
        char omap[LIMIT][LIMIT]={};
        char rmap[LIMIT][LIMIT]={};
        for (int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                cin >> omap[i][j];
            }
        }
        
//        for (int i=0;i<size;i++) {
//            for(int j=0;j<size;j++) {
//                printf("%c", omap[i][j]);
//            }
//            cout << endl;
//        }
        
        for (int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                char temp;
                cin >> temp;
                
                if(temp == CLICK) {
                    if(omap[i][j] == MINE) {
                        rmap[i][j] = MINE;
                        isMineClick = 1;
                    }
                    else {
                        rmap[i][j] = checkmine(omap, size, i, j);
                    }
                }
                else if(isMineClick && omap[i][j] == MINE) {
                    rmap[i][j] = MINE;
                }
                else {
                    rmap[i][j] = EMPTY;
                }
            }
        }
        
        for (int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                printf("%c", rmap[i][j]);
            }
            cout << endl;
        }
        
    }
    
    return 0;
}

char checkmine(char omap[LIMIT][LIMIT], int size, int i, int j) {
    char cnt=0;
    
    //printf("%c %d %d %d\n", omap[i][j], size, i,j);
    
    if(i-1>=0 && j-1>=0 && omap[i-1][j-1] == MINE)
        cnt++;
    if(i-1>=0  && omap[i-1][j] == MINE)
        cnt++;
    if(i-1>=0 && j+1<size && omap[i-1][j+1] == MINE)
        cnt++;
    if(j-1>=0 && omap[i][j-1] == MINE)
        cnt++;
    if(j+1<size && omap[i][j+1] == MINE)
        cnt++;
    if(i+1<size && j-1>=0 && omap[i+1][j-1] == MINE)
        cnt++;
    if(i+1<size && omap[i+1][j] == MINE)
        cnt++;
    if(i+1<size && j+1<size && omap[i+1][j+1] == MINE)
        cnt++;
    
    if(cnt != 0)
        return cnt+'0';
    else
        return EMPTY;
}