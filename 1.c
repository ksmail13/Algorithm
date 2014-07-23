#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 50

#define ABSO(x) (((x) < 0) ? (-1*(x)) : (x))



struct listnode {
	int data;
	struct listnode *next;
};

int main() {
	int testcase;
	scanf("%d", &testcase);
	while(testcase--) {
		int numcnt;
		int i,j, t;
		struct listnode narr[LIMIT] = {};
		struct listnode *temp;
		scanf("%d", &numcnt);
		
		// 숫자 입력
		for(i=1;i<=numcnt;i++) {
			scanf("%d", &j);
			narr[i].data = j;
			// 입력하고 다음 노드와 연결
			if(i+1 <= numcnt)
				narr[i].next = &narr[i+1];
			else
				// 마지막 노드이면 NULL
				narr[i].next = NULL;
		}
		
		
		// 연산실행
		for(i=0;i<numcnt-1;i++) {
			scanf("%d", &j);
			temp = &narr[1];
			t = j;
			while(--t && temp) {
				temp = temp->next;
			}
			//printf("index :%d data : %d next data : %d\n", j, temp->data, temp->next->data);
			// 데이터를 축소 저장
			temp->data = ABSO(temp->data - temp->next->data);
			// 다음 데이터를 변경
			temp->next = temp->next->next;
		}
		
		printf("%d\n", narr[1].data);
	}
	return 0;
}