#include <stdio.h>
#define LIMIT 11

char map[LIMIT][LIMIT];
char cmap[LIMIT][LIMIT];
char tmap[LIMIT][LIMIT];
int n;

int mapcmp(char m1[LIMIT][LIMIT], char m2[LIMIT][LIMIT]) {
	int i, j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(m1[i][j] != m2[i][j]) {
				printf("i %d j %d m1 %d m2 %d\n",i, j, m1[i][j], m2[i][j]);
				return 0;
			}
		}
	}
	
	return 1;
}

void printmap(char m[LIMIT][LIMIT]) {
	int i=0, j;
	for (i=0;i<=n;i++) {
		for(j=0;j<=n;j++)
			printf("%d", m[i][j]);
		putchar('\n');
	}
}

void mapcpy(char m1[LIMIT][LIMIT], char m2[LIMIT][LIMIT]) {
	int i, j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			m1[i][j] = m2[i][j];
		}
	}
}

int is90() {
	int i, j;
	for(i=0;i<=n;i++) {
		for(j=0;j<=n;j++) {
			tmap[j][n-i] = map[i][j];
		}
	}
	printf("tmap:\n");
	printmap(tmap);
	return mapcmp(cmap, tmap);
}

int is180() {
	int i, j;
	for(i=0;i<=n;i++) {
		for(j=0;j<=n;j++) {
			tmap[n-i][n-j] = map[i][j];
		}
	}
	printf("tmap:\n");
	printmap(tmap);
	return mapcmp(cmap, tmap);
}

int is270() {
	int i, j;
	for(i=0;i<=n;i++) {
		for(j=0;j<=n;j++) {
			tmap[n-j][i] = map[i][j];
		}
	}
	printf("tmap:\n");
	printmap(tmap);
	return mapcmp(cmap, tmap);
}

int isreverse() {
	int i, j;
	for(i=0;i<=n;i++) {
		for(j=0;j<=n;j++) {
			tmap[i][n-j] = map[i][j];
		}
	}
	printf("tmap:\n");
	printmap(tmap);
	return mapcmp(cmap, tmap);
}

int iscombi() {
	isreverse();
	mapcpy(map, tmap);
	if(is90()) return 1;
	if(is180()) return 1;
	if(is270()) return 1;
	
	return 0;
}


int main() {
	int testcase;
	char temp_str[LIMIT];
	
	// 반복 인덱스
	int i,j,k;
	scanf("%d", &testcase);
	
	while(testcase--) {
		int issamemap = 0;
		scanf("%d", &n);
		
		for(i=0;i<n;i++) {
			scanf("%s", temp_str);
			for(j=0;j<n;j++) {
				map[i][j] = temp_str[j];
			}
		}
		
		
		for(i=0;i<n;i++) {
			scanf("%s", temp_str);
			for(j=0;j<n;j++) {
				cmap[i][j] = temp_str[j];
			}
		}
		
		issamemap = mapcmp(map, cmap);
		
		if(is90()){
			printf("1\n");
		}
		else if(is180()){
			printf("2\n");
		}
		else if(is270()){
			printf("3\n");
		}
		else if(isreverse()){
			printf("4\n");
		}
		else if(iscombi()){
			printf("5\n");
		}
		else if(issamemap) {
			printf("6\n");
		}
		else {
			printf("7\n");
		}
		
	}
	
	return 0;
}