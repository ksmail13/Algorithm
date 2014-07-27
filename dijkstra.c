#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LIMIT 1010

#define MIN(x, y) ((x) > (y)? (y): (x))

unsigned int map[LIMIT][LIMIT];
unsigned int dmap[LIMIT][LIMIT];
unsigned int visit[LIMIT][LIMIT];
int route[LIMIT];
int r_idx;

struct data {
    int target;
    int len;
};

int min(int x, int y) {
    if(x>y)
        return y;
    else
        return x;
}

// 그래프 초기화
void map_init(int vcnt) {
    int i,j;
    for(i=0;i<=vcnt;i++) {
        for(j=0;j<=vcnt;j++) {
            // 데이터를 최대값으로 초기화
            dmap[i][j] = INT_MAX;
        }
    }
}

void dmap_print(int vcnt) {
    int i,j;
    for(i=1;i<=vcnt;i++) {
        for(j=1;j<=vcnt;j++) {
            printf("%10u ", dmap[i][j]);
        }
        putchar('\n');
    }
}

int compare(const void *d1, const void *d2) {
    int num1 = ((struct data *)d1)->len;
    int num2 = ((struct data *)d2)->len;
	
    return num1-num2;
}

void visit_init(int vcnt) {
	int i,j;
	for (i=0;i<vcnt; i++) {
		for (j=0; j<vcnt; j++) {
			visit[i][j] = 0;
		}
	}

}

int short_path(const int start, const int target, int vcurr, int vcnt, const unsigned int distance) {
    int i;
    struct data q[LIMIT];
    int front=0, rear=0;
//    printf("start %d target %d vcurr %d vcnt %d distance %u\n", start, target, vcurr, vcnt, distance);
    // 목표 노드 까지의 최소 거리를 찾았을 때
    if(vcurr == target && distance == dmap[start][target]) {
        for(i=0;i<r_idx;i++) {
            printf("%d ", route[i]);
        }
        putchar('\n');
        return 1;
    }
	
    for(i=1;i<=vcnt;i++) {
		//        printf("vcurr %d i %d map[%d][%d] && !visit[%d][%d] %s\n", vcurr, i, vcurr, i, vcurr,i, (map[vcurr][i] && !visit[vcurr][i])?"true":"false");
        if(map[vcurr][i] && !visit[vcurr][i]) {
            q[rear].target = i;
            q[rear++].len = map[vcurr][i];
            // 기존 시작점과의 거리와 vcurr를 거쳐 가는 경로 중 짧은 것을 저장한다.
            dmap[start][i] = min(dmap[start][i], distance+map[vcurr][i]);
            dmap[i][start] = dmap[start][i];
			//            printf("dmap[%d][%d] = %d map[%d][%d] = %d \n", start, i, dmap[start][i], vcurr, i, map[vcurr][i]);
            visit[vcurr][i] = 1;
            visit[i][vcurr] = 1;
        }
    }
	
    // sort
    qsort(q, rear, sizeof(struct data), compare);
	
    while(front<rear) {
        int u = q[front++].target;
        route[r_idx++] = u;
//        printf("dmap[%d][%d] = %d map[%d][%d] = %d distance = %d\n", start, u, dmap[start][u], vcurr, u, map[vcurr][u], distance);
        if(short_path(start, target, u, vcnt, distance+dmap[vcurr][u])) {
			// 방문지 초기화
            visit[vcurr][u] = 0;
            visit[u][vcurr] = 0;
			r_idx--;
            return 1;
        }
        r_idx--;
        visit[vcurr][u] = 0;
        visit[u][vcurr] = 0;
    }
	
    return 0;
}

int main() {
    // vertex count, edge count, start point
    int vcnt, ecnt, spnt;
    int i;
    scanf("%d %d %d", &vcnt, &ecnt, &spnt);
	
    map_init(vcnt);
	
    for(i=0;i<ecnt;i++) {
        int v1, v2, len;
        scanf("%d%d%d", &v1, &v2, &len);
        // v1 에서 v2 까지 len 만큼 떨어져 있다.
        map[v1][v2] = len;
        map[v2][v1] = len;
        dmap[v1][v2] = len;
        dmap[v2][v1] = len;
    }
	
	printf("%d\n", spnt);
	
    for(i=2;i<=vcnt;i++) {
        route[r_idx++] = spnt;
        short_path(spnt, i, spnt, vcnt, 0);
        r_idx--;
		visit_init(vcnt);
    }
	
//    dmap_print(vcnt);
	
    return 0;
}

