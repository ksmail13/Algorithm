#include <stdio.h>
#define LIMIT 3000
#define QSIZE 9000000

#define ONE 2
#define ZERO 1
#define SIDE 0

#define MAX(x,y) ((x) > (y) ? (x):(y))

struct point {
	int x,y;
};



int main() {
	int testcase;
	char temp_str[LIMIT];
	// 반복 인덱스
	int i,j,k;
	// 좌표 저장용
	int x,y, ox, oy, tx;
	scanf("%d", &testcase);
	
	while(testcase--) {
		int m,n;
		scanf("%d %d", &n, &m);
		
		for(i=0;i<n;i++) {
			scanf("%s", temp_str);
			for(j=0;j<m;j++) {
			
				//printf("data : %d j: %d i: %d\n", temp_str[j]-'0'+1, j,i);
				// 1 -> 2, 0 ->1 로 저장 0은 경계
				map[i][j] = temp_str[j]-'0'+1;
				if(temp_str[j]=='1') {
					p[pidx].y = i;
					p[pidx].x = j;
					pidx++;
				}
			}
		}
	
	/*
		int map[LIMIT][LIMIT] = {};
		struct point p[QSIZE];
		int pidx=0;
		int n, m;
		int max_size=0;
		scanf("%d %d", &n, &m);
		
		// 지도 데이터 저장 및 체크해야할 좌표 값 설정
		for(i=0;i<n;i++) {
			scanf("%s", temp_str);
			for(j=0;j<m;j++) {
			
				//printf("data : %d j: %d i: %d\n", temp_str[j]-'0'+1, j,i);
				// 1 -> 2, 0 ->1 로 저장 0은 경계
				map[i][j] = temp_str[j]-'0'+1;
				if(temp_str[j]=='1') {
					p[pidx].y = i;
					p[pidx].x = j;
					pidx++;
				}
			}
		}
		
		// 지도에 1인 점들을 순회하면서 사각형의 넓이를 구한다.
		for(k=0;k<pidx;k++) {
			//if(check[q[k].y][q[]
			// ox는 최소의 너비를 저장하기 위해서
			// oy는 최대의 y를 저장하기 위해서
			ox = x = p[k].x;
			oy = y = p[k].y;
			
			//printf("one point x:%d y:%d\n", x, y);
			
			// 너비구하기
			while(map[y][x] == ONE) {
				x++;
			}
			x--;
			
			// 높이 구하기
			while(map[y][ox] == ONE) {
				//
				tx = ox;
				// 다음 라인의 최대 x를 구함
				while(map[y][tx] == ONE && tx <= x+1) {
					tx++;
				}
				tx--;
				if(tx < x) x = tx;
				//printf("curr size : (%d - %d + 1) * (%d - %d + 1) = %d\n", x+1,ox+1,y+1,oy+1,(x-ox+1)*(y-oy+1));
				max_size = MAX((x-ox+1)*(y-oy+1), max_size);
				
				y++;
			}
			y--;
			
			if(max_size == n*m)
				break;
			//printf("x: %d xend: %d y: %d yend: %d size : %d\n", p[k].x, p[k].y, x,y, (x-p[k].x+1)*(y-p[k].y+1));
			
		}
		
		printf("%d\n", max_size);
		*/
	}
	
	return 0;
}