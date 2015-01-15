#include <stdio.h>

int fact[101];

int main() {
    int i,j;
    int n;
    for (i=1;i<101;i++) {
        fact[i] = 1;
    }

    for(i=2;i<101;i++) {
        for(j=i;j<101;j+=i) {
            fact[j]++;
        }
    }

    scanf("%d", &n);

    printf("%d\n", fact[n]);

}
