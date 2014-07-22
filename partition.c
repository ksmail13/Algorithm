#include <stdio.h>
#define LIMIT 54

int main() {
    int t[LIMIT] = {};
    int i,j, n;

    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        t[i] = 1;
    }

    for(j=2;j<=n;j++) {
        for(i=j;i<=n;i++) {
            if(i==j) t[i]++;
            else if(i>j) {
                t[i] = t[i] + t[i-j]; 
            }
        }
    }

    printf("%d\n", t[n]);
    return 0;
}
