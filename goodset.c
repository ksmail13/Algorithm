#include <stdio.h>
#define LIMIT 501
int main() {
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        int n, m, i, j;
        int map[LIMIT][LIMIT] = {};
        int corr[LIMIT] = {};

        int yes = 1;
        scanf("%d %d" , &n, &m);
        for(i=1;i<=n;i++) {
            int c;
            scanf("%d", &c);
            if(c == m || c==0) {
                yes = 0;
            }
            for(j=1;j<=c;j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for(i=1;i<=n;i++) {
            for(j=1;map[i][j]!=0;j++) {
                corr[map[i][j]]++;
            }
        }

        for(i=1;i<=m;i++) {
            if(corr[i]==0){

                yes = 0;
            }
        }

        if(yes) {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
