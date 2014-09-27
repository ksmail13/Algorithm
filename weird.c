#include <stdio.h>
#define LIMIT 500001
#define SQRT_LIMIT 708
long long list[LIMIT][4] = {};
int visit[LIMIT] = {};

void onnum(long long num[4], int index) {
    index--;
    int block_idx = index/sizeof(long long);
    int bit_idx = index%sizeof(long long);
    /*if(num == list[12])
        printf("index %d block %d bit %d\n", index, block_idx, bit_idx);
    */
    num[3-block_idx] = num[3-block_idx] | 1 << bit_idx;

}

int checknum(long long num[4], int index) {
    index--;
    int block_idx = index/sizeof(long long);
    int bit_idx = index&sizeof(long long);

    return num[3-block_idx] & 1 << bit_idx;
}

void initlist() {
    int i,j;
    //printf("%d %d %d %d\n", list[12][0], list[12][1], list[12][2], list[12][3]);
    for(i=1;i<LIMIT;i++) {
        for(j=i+i;j<LIMIT;j+=i) {
            

            //list[j][visit[j]]=i;
            onnum(list[j], i);
            visit[j]++;
            /*if(j==12) {
                printf("i = %d j = %d \n", i,j);
                printf("check j on i %d\n", checknum(list[j], i));
            }*/
        }
    }
}

int find(int n, int index, int sum) {
    //printf("n %d index %d curr sum %d\n",n, index,sum);
    if(n == sum) return 1;
    if(index>visit[n]) return 0;
    int i=index;
    int check = 0;
    while((check=checknum(list[n], i++)) == 0) {
    //    printf("check = %d\n", check);
    }
    //printf("i = %d check = %d\n",i-1, check);
    if(find(n, i, sum+i)) {
        return 1;
    }
    if(find(n, i, sum)) {
        return 1;
    }

    return 0;
}

int main() {
    int tcase;
    initlist();
    int i=0, max = 0;
    for(i=1;i<LIMIT;i++) {
        if(max < visit[i])
            max=visit[i];
    }

    //printf("max = %d\n", max);
    scanf("%d", &tcase);
    while(tcase--) {
        int n;
        scanf("%d", &n);
        //printf("n %d list[%d] = %d\n", n,n,list[n][visit[n]-1]);
        if(find(n, 0 ,0))
            printf("%d not weird\n", n);
        //else
        //    printf("weird\n");
            
    }

    return 0;
}
