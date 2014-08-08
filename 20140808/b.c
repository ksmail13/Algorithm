#include <stdio.h>
#define LIMIT 100
#define QLIMIT 10000
#define CHK_CNT 4

int map[LIMIT][LIMIT];

struct point {
    int y,x;
};

struct point q[QLIMIT];
int q_start, q_rear;
struct point del[LIMIT];
int del_idx;

const int ychk[] = {-1, 0, 0, 1};
const int xchk[] = {0, -1, 1, 0};

void printmap(int n, int m) {
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			printf("%d ", map[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	putchar('\n');
	putchar('\n');
}

int main()
{
    int tcase;
    int i,j;
    scanf("%d", &tcase);
	
    while(tcase--) {
		// h time of melt all cheese
        int n, m, h, end;
		
        q_start = 0;
        q_rear = 0;
        scanf("%d %d", &n, &m);
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					q[q_rear].x = j;
					q[q_rear++].y = i;
				}
            }
        }
		
		for (h=1; q_start<q_rear; h++) {
			int del_idx = 0;
			end = q_rear;
			for(; q_start<end; q_start++) {
				int scnt=0;
				int x = q[q_start].x;
				int y = q[q_start].y;
				
				for (i=0; i<CHK_CNT; i++) {
					if(map[y+ychk[i]][x+xchk[i]] == 0) {
						scnt++;
					}
				}
				// 주변의 빈공간의 갯수
				if (scnt < 2) {
					// 생존 치즈 등록
					q[q_rear].x = x;
					q[q_rear++].y = y;
				}
				else {
					// 소멸 치즈 등록
					del[del_idx].x = x;
					del[del_idx++].y = y;
				}
			}
			// 치즈 소멸
			for (i=0; i<del_idx; i++) {
				map[del[i].y][del[i].x] = 0;
			}
			
			printmap(n, m);
		}
		
        printf("%d\n", h-1);
    }
    return 0;
}

