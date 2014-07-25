#include <stdio.h>
#include <string.h>

#define LIMIT 1000
#define ISNUM(x) ((x) >= '0' && (x) <='9')
char fix[LIMIT];

int string_to_num(char *num, int numlen) {
    int i=0, result=0;
    for(i=numlen-1;i>=0;i--) {
        result = result*10+(num[i]-'0');
    }
    //printf("numstr %s result %d\n", num, result);

    return result;
}

int main() {
    int testcase, i, fixlen;
    int result=0;
    scanf("%d", &testcase);
    while(testcase--) {
        char temp[LIMIT]={};
        int a=0,c=0;
        int tempidx=0;
        scanf("%s", fix);
        fixlen = strlen(fix);
        for(i=0;i<fixlen;i++) {
            if(ISNUM(fix[i])) {
                temp[tempidx++] = fix[i];
                //printf("fix : %s fix[%d] = %c\n",fix,  i, fix[i]);
            }
            else if(!result) {
                if(a == 0)
                    a = string_to_num(temp, tempidx);
                else
                    a += string_to_num(temp, tempidx);
//                printf("a = %d\n", a);
                tempidx=0;
                if(fix[i] == '=')
                    result = 1;
            }
        }

        c = string_to_num(temp, tempidx);
        //printf("a = %d, c = %d\n", a, c);
        if(a==c)
            printf("True\n");
        else
            printf("False\n");
        a=0;
        result = 0;
        
    }

    return 0;
}
