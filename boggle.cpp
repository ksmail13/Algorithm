#include <iostream>
#include <cstdio>

#define COUNT 5
#define MAX_WORD_LENGTH 12
char map[COUNT][COUNT];

int findstring(char *msg, int stridx, int len, int x, int y);

int main() {
    int tcase;
    int i,j,k;
    char buf[MAX_WORD_LENGTH];
    int result;
    scanf("%d", &tcase);

    while(tcase--) {
        int wordcnt;
        for(i =0;i<COUNT;i++) {
            for(j=0;j<COUNT;j++) {
                scanf("%c", &map[i][j]);
            }
        }
        scnaf("%d", &wordcnt);

        for(k=0;k<wordcnt;k++) {
            scanf("%s", buf);

            for(i=0;i<COUNT;i++) {
                for(j=0;j<COUNT;j++) {
                    if(buf[0] == map[i][j]) {
                        result = findstring(buf, 0, strlen(buf), j, i);
                    }
                }
            }
            printf("%s ", buf);
            if(result == 1) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }

        }

        
    }
    return 0;
}


int findstring(char *msg, int stridx, int len, int x, int y) {
    int xchk[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int ychk[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
}
