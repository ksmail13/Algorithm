#include <stdio.h>

void ptp(int i) {
	if(i<=0) return;
	ptp(i-1);
	printf("%d", i);
	ptp(i-1);
}

int main()
{
	int num;
	scanf("%d", &num);

	ptp(num);
    putchar('\n');
	return 0;
}
