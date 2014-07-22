#include <stdio.h>
#define LIMIT 15
#define ROUTE_CNT 3

int route[ROUTE_CNT][LIMIT];
int rcnt;
int mapsize;

struct point{
    int x,y;
};

struct pointlist{
    struct point arr[LIMIT];
    int size;
};
struct pointlist pl;

int setQ( int y, int x) {
    int i;

    //check point routine
    for(i=0;i<pl.size;i++) {
        struct point pt = pl.arr[i];
        if(pt.x == x || pt.y-pt.x == y-x || pt.y+pt.x == y+x) return 0;
    }
    // add point routine
    pl.arr[pl.size].y = y;
    pl.arr[pl.size].x = x;
    pl.size++;

    if(rcnt < ROUTE_CNT) {
        route[rcnt][y] = x;
    }
    if(y == mapsize) {
        rcnt++;
    }

    for(i=1;i<=mapsize&& y < mapsize;i++) {
        setQ(y+1, i);
    }
    pl.size--;
    return 0;
}

int main() {

    int i,j;
    scanf("%d", &mapsize);
    for(i=1;i<=mapsize;i++) {
        setQ(1, i);
    }

    for(i=0;i<ROUTE_CNT;i++) {
        for(j=1;j<=mapsize;j++){
            if(route[i][j] == 0)
                route[i][j] = route[i-1][j];
            printf("%d ", route[i][j]);
        }
        putchar('\n');
    }
    printf("%d\n", rcnt); 

    return 0;
}
