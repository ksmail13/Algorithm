#include <stdio.h>
#define LIMIT 500

#define ABS(x) (x) < 0? -1*(x) : (x)
#define MIN(a,b) (a) > (b) ? (b) : (a)

int main()
{
    int fam_cnt;
    int family[500]={};
    int i,j;
    int min_d=0x7fffffff, tmp_d;
    int curr;

    scanf("%d", &fam_cnt);

    for(i=0;i<fam_cnt;i++) {
        scanf("%d", &family[i]);
    }

    for(i=0;i<fam_cnt;i++) {
        curr = family[i];
        tmp_d=0;

        for(j=0;j<fam_cnt;j++) {
            tmp_d += (ABS(curr-family[j]));
            if(tmp_d > min_d)
                break;
        }

        min_d = MIN(min_d, tmp_d);
    }

    printf("%d\n", min_d);


    return 0;
}
