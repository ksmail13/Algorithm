#include <stdio.h>
#include <string.h>
#define LIMIT 1000000000

int main() {
    int tcase;
    short int map[LIMIT];
    int i,j;
    scanf("%d", &tcase);
    while(tcase--) {
        int n,s,e;
        int max=0, wmax=0, wmax_idx;
        memset(map, 0, sizeof(short int)*LIMIT);
        scanf("%d", &n);

        for(i=0;i<n;i++) {
            scanf("%d %d", &s,&e);
            for(j=s; j<=e;j++) {
                map[j]++;
                if(max<map[j])
                    max = map[j];
            }
        }


    }

    return 0;
}
