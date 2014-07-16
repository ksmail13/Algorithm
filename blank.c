#include <stdio.h>
#include <string.h>

#define LIMIT 200
#define TRUE 1
#define FALSE 0

struct blank {
    int open;
    int index;
};

int main() {
    int i, j;
    int piriority = 1;
    char buf[LIMIT] = {};
    struct blank blankStat[LIMIT] = {};
    int bufpriority[LIMIT] = {};
    
    scanf("%s", buf);
    
    for(i=0;i<strlen(buf);i++) {
        if(buf[i] == '(')
        {
            blankStat[i].open = TRUE;
            blankStat[i].index = i;
        }
        else
        {
            blankStat[i].open = FALSE;
            blankStat[i].index = i;
            
            bufpriority[i] = piriority;
            j=i;
            while(blankStat[--j].open == FALSE){}
            blankStat[j].open = FALSE;
            bufpriority[blankStat[j].index] = piriority;
            
            piriority++;
        }
    }
    if(bufpriority[i] != 0)
        for(i=0;i<strlen(buf);i++) {
            printf("%d ", bufpriority[i]);
        }
    else
        printf("WRONG EXPRESSION\n");
    return 0;
}