#include <stdio.h>


#define LIMIT 3001
#define DEBUG_SYM printf("pass : %d\n", __LINE__)
#define ABS(a) (a) < 0? -1*(a):(a)

int main() 
{
    int n;
    int chk[LIMIT] = {};
    int chk_cnt=0;
    int i;
    int input, b_input;
    scanf("%d", &n);

    scanf("%d", &input);
    for(i=1;i<n;i++) {
        b_input = input;

        scanf("%d", &input);
        if(!chk[ABS(input-b_input)]) {
            chk[ABS(input-b_input)]=1;
        }
        else {
            printf("Not jolly\n");
            return 0;
        }
    }

    for(i=1;i<n;i++) {
        if(!chk[i]) {
            printf("Not jolly\n");
            return 0;
        }
    }

    printf("Jolly\n");

    return 0;
}
