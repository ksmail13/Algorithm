#include <iostream>
#include <cstdio>
#define LIMIT 10000

int node[LIMIT][LIMIT];

int main() {
	int tcase;
    int i,j;
	scanf("%d", &tcase);
	
	while(tcase--) {
		int ncnt;
		int n,m;
		int find=0;
		
		int nroute[LIMIT]={};
		int n_idx=0;
		int mroute[LIMIT]={};
		int m_idx=0;
		scanf("%d", &ncnt);
		
		// 트리입력
		for (i=0; i<ncnt-1; i++) {
			
			scanf("%d %d", &n, &m);
			
			//node[n][m] = 1;
			node[m][n] = 1;
		}
		// 대상
		scanf("%d %d", &n, &m);
		
		// 루트까지 거슬러가면서 체크
		nroute[n_idx++]=n;
		while (1) {
			for (i=0; i<ncnt; i++) {
				if(node[n][i]){
					nroute[n_idx++]=i;
					n = i;
					find = 1;
					break;
				}
				else find = 0;
			}
			if (!find) {
				
				break;
			}
		}
		find =0;
		
		mroute[m_idx++]=m;
		while (1) {
			for (i=0; i<ncnt; i++) {
				if(node[m][i]){
					mroute[m_idx++]=i;
					m = i;
					find =1;
					break;
				}
				else find = 0;
			}
			if (!find) {
				
				break;
			}
		}
		
		// 각각 비교
		for (i=0; i<n_idx; i++) {

			for (j=0; j<m_idx; j++) {
				if (nroute[i] == mroute[j]) {
					printf("%d\n", nroute[i]);
					find = 1;
					break;
				}
			}
			if (find) {
				break;
			}
		}
	
	}
	return 0;
}
