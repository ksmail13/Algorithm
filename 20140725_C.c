#include <stdio.h>
#define LIMIT 100

char buf[LIMIT];
int bufidx;

void get_num_case(int onecnt, int numlen, int print) {
    int i=0;
    if(!onecnt && !numlen) { 
        return;
    }
    if(print && onecnt > 0) {
        onecnt--;
        buf[bufidx++] = '1';
    }
    else {
        buf[bufidx++] = '0';
    }

    if(numlen>1) {
        if(onecnt == numlen) {
            for(i=0;i<onecnt;i++)
                buf[bufidx++] = '1';
            printf("%s\n", buf);
            bufidx -= i;
            return ;
        }
        else {
            if(onecnt)
                get_num_case(onecnt, numlen-1, 1);
            if(onecnt != numlen-1)
                get_num_case(onecnt, numlen-1, 0);
        }
    }
    else {
        buf[bufidx] = '\0';
        printf("%s\n", buf);
    }
    bufidx--;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int n,k;
        scanf("%d %d", &n, &k);

        get_num_case(k, n, 1);
        if(k!=0 && k != n)
            get_num_case(k, n, 0);
    }
    return 0;
}
