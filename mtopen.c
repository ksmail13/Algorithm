#include <stdio.h>

void recprint(int n, int limit) {
	prirtf("%d", n);
	if(n < limit){
		recprint(n+1, limit);
		printf("%d", n);
	}
}

int main() {
	int num;
	scanf("%d", &num);

	recprint(1, num);
	putchar('\n');
	return 0;
}
