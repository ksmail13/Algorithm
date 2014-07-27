#include <stdio.h>
#define BLOCK_COUNT 3
#define LIMIT 10

char m[LIMIT][LIMIT];
char v[LIMIT][LIMIT];
int zero_cnt;

int search_horizontal(int x, int y) {
    // line zeros count
    int i, lzc=0;
    int check = 45;
    for(i=0;i<LIMIT-1;i++) {
        if(!m[y][i]){
            lzc++;
        }
        else {
            check -= m[y][i];
        }
    }

    if(lzc == 1) {
//        printf("%s change %d\n",__FUNCTION__, check);
        m[y][x] = check;
        v[y][x] = 0;
        zero_cnt--;
        return 1;
    }

    return 0;
}

int search_vertical(int x, int y) {
    // line zeros count
    int i, lzc=0;

    int check = 45;
    for(i=0;i<LIMIT-1;i++) {
        if(!m[i][x]){
            lzc++;
        }
        else {
            check -= m[i][x];
        }
    }

    if(lzc == 1) {
//        printf("%s change %d\n",__FUNCTION__, check);
        m[y][x] = check;
        v[y][x] = 0;
        zero_cnt--;
        return 1;
    }
    return 0;
}

int search_block(int x, int y) {
    // block zeros count
    int i, j, bzc=0;
    int visit[LIMIT][LIMIT] = {};
    int check = 45;
    int minx = x/BLOCK_COUNT*BLOCK_COUNT, maxx = x/BLOCK_COUNT*BLOCK_COUNT+BLOCK_COUNT;
    int miny = y/BLOCK_COUNT*BLOCK_COUNT, maxy = y/BLOCK_COUNT*BLOCK_COUNT+BLOCK_COUNT;
   
//    printf("min y %d max y %d min x %d max x %d\n", miny, maxy, minx, maxx);
    for(i=miny;i<maxy;i++) {
        for(j=minx;j<maxx;j++) {
//            printf("i %d,j %d, m[%d][%d] %d\n", i, j,i,j, m[i][j]);
            if(m[i][j] == 0) {
                visit[i][j] = 1;
                bzc++;
            }
            else
                check -= m[i][j];
        }
    }
    
    if(bzc == 1) {
//        printf("change %d\n", check);
        m[y][x] = check;
        v[y][x] = 0;
        zero_cnt--;
        return 1;
    }
    return 0;
}

void map_print() {
    int i,j;
    for(i=0;i<LIMIT-1;i++) {
        for(j=0;j<LIMIT-1;j++) {
            printf("%d", m[i][j]);
        }
        putchar('\n');
    }
}

int main() 
{
    int i,j;

    for(i=0;i<LIMIT-1;i++) {
        scanf("%s", m[i]);
        for(j=0;j<LIMIT-1;j++) {
            m[i][j] = m[i][j] - '0';
            if(m[i][j] == 0) {
                v[i][j] = 1;
                zero_cnt++;
            }
        }
    }
    

    while(zero_cnt) {
        for(i=0;i<LIMIT-1;i++) {
            for(j=0;j<LIMIT-1;j++) {
                if(v[i][j]){
                    if(search_horizontal(j,i)) {
                        //map_print();
                        //getchar();
                    }
                    else if(search_vertical(j,i)) {
                        //map_print();
                        //getchar();
                    }
                    else if(search_block(j,i)) {
                        //map_print();
                        //getchar();
                    }
                }
            }
        }
    }
    
    map_print();

    return 0;
}
