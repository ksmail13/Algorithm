#include <stdio.h>
#define R_MIN 10
#define R_MAX 1000000

int facts[10]={1,};

int fact(int n) {
    int i=1;
    while(n) {
        i*=n;
        n--;
    }

    return i;
}
int fact[1000000] = {};
// 10  = 1 101 102 103 104 .... 10+n!
//
void initfacts() {
    int i;

    for(i=1;i<10;i++) {
        facts[i] = fact(i);
        //printf("fact %d:%d\n",i, facts[i]); 
    }
}

int main() 
{
    int i,j;
    int sum;
    initfacts();
    for(i=R_MIN;i<=R_MAX;i++) {
        j=i;
        sum = 0;
        while(j) {
            sum += facts[j%10];
            j/=10;
        }
        //printf("sum : %d, i: %d\n", sum, i); 
        if(i==sum) {
            printf("%d\n", i);
        }
    }
    return 0;
}
