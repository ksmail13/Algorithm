#include <stdio.h>
#include <string.h>

#define OPEN(c) ((c) == '(' || (c) == '[')

#define LIMIT 1000

struct data{
    int data;
    int index;
};

int sametype(char o, char c) {
    if(o == '(') {
        return (c == ')');
    }
    else {
        return (c == ']');
    }
}

int bton(char b) {
    if(b == '(')
        return 2;
    else if(b =='[')
        return 3;
    else 
        return 0;
}

int main() {
    int tcase;
    int i,j;
    scanf("%d", &tcase);

    while(tcase--) {
        char buf[LIMIT] = {};
        int buflen;
        struct data s[LIMIT] = {};
        int s_idx=0;
        struct data nums[LIMIT] = {};
        int nums_idx=0;
        int b_close = 0;
        int temp=0, error=0;
        scanf("%s", buf);
        buflen = strlen(buf);
//        printf("start\n");

        for(i=0;i<buflen;i++) {
            if(OPEN(buf[i])) {
                s[s_idx].data = buf[i];
                s[s_idx++].index = i;
                b_close = 0;
            }
            else if(sametype(s[s_idx-1].data, buf[i])) {
                temp = 0;
                if(b_close) {
                    while(nums[nums_idx-1].index > s[s_idx-1].index) {
                        temp += nums[--nums_idx].data;
//                        printf("add %d to temp : %d\n", nums[nums_idx+1].data, temp);
                    }
                    temp *= bton(s[--s_idx].data);
                    nums[nums_idx++].data = temp;

//                    printf("multi data temp %d\n", temp);
                }
                else {
                    nums[nums_idx].data = bton(s[s_idx-1].data);
                    nums[nums_idx++].index = s[--s_idx].index;
/*                    printf("push num stack %d index %d\n", nums[nums_idx-1].data, nums[nums_idx-1].index);
                    for(j=0;j<nums_idx;j++) {
                        printf("%d ", nums[j].data);
                    }
                    putchar ('\n');
*/
                }
                b_close = 1;
            }
            else {
                printf("0\n");
                error = 1;
                break;
            }
        }
        if(error) continue;
/*        for(j=0;j<nums_idx;j++) {
            printf("%d ", nums[j].data);
        }
        putchar ('\n');*/
        if(s_idx){ 
            printf("0\n");
            continue;
        }

        temp = 0;
        while(nums_idx--) {
            temp += nums[nums_idx].data;
        }


        printf("%d\n", temp);

    }
    return 0;
}
