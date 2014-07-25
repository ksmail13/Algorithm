#include <stdio.h>
#include <string.h>
#define LIMIT 10000
char optors[LIMIT];
int optor_idx;
int nums[LIMIT];
int num_idx;

#define CONVERSION(x) ((x) == '+' || (x) == '-') ? 1:2
#define IS_OPTOR(x) ((x) == '+' || (x) == '-' || (x) == '*' || (x) == '/')
int checkoptor(char a, char b) {
    int oa = CONVERSION(a), ob = CONVERSION(b);
    return oa-ob; 
}


int main() {
    int testcase;
    scanf("%d", &testcase);

    while(testcase--) {
        char t[LIMIT] = {};
        int tlen, i;
        int num1, num2;
        int divideZ = 0;
        scanf("%s", t);
        tlen = strlen(t);

        for(i=0;i<tlen;i++) {
            if( IS_OPTOR(t[i])) {

                if(optor_idx > 0 && checkoptor(optors[optor_idx-1], t[i]) > 0) {
                    num2 = nums[--num_idx];
                    num1 = nums[--num_idx];

                    char optor = optors[--optor_idx];
                    switch(optor) {
                        case '+':
                            nums[num_idx++] = num1+num2;
                            break;
                        case '-':
                            nums[num_idx++] = num1-num2;
                            break;
                        case '*':
                            nums[num_idx++] = num1*num2;
                            break;
                        case '/':
                            if(num2 != 0) 
                            nums[num_idx++] = num1/num2;
                            else {
                                printf("Divide by zero\n");
                                divideZ = 1;
                            }
                            break;
                    }
                    optors[optor_idx++] = t[i];
                }
                else {
//                    printf("add optor [%d] %c\n", i, t[i]);
                    optors[optor_idx++] = t[i];
                }
                if(divideZ) break;
            }
            else {
//                printf("add num [%d] %d\n",i, t[i]-'0');
                nums[num_idx++] = t[i] - '0';
            }
        }

        while(optor_idx--) {
            char optor = optors[optor_idx];
            num2 = nums[--num_idx];
            num1 = nums[--num_idx];
            switch(optor) {
                case '+':
                    nums[num_idx++] = num1+num2;
                    break;
                case '-':
                    nums[num_idx++] = num1-num2;
                    break;
                case '*':
                    nums[num_idx++] = num1*num2;
                    break;
                case '/':
                    if(num2 != 0) 
                        nums[num_idx++] = num1/num2;
                    else {
                        printf("Divide by zero\n");
                        divideZ = 1;
                    }
                    break;
            }

        }
        if(divideZ == 0)
            printf("%d\n", nums[0]);
        optor_idx = 0;
        num_idx = 0;
    }
    return 0;
}
