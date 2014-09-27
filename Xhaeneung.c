#include <stdio.h>
#include <string.h>

int string_to_num(char *str);
int check_num_string(char *str, int num);
void init_num_map();
char num_map[10][26] = {};


int main() {
    int tcase;
    scanf("%d", &tcase);
    init_num_map();
    getchar();
    while(tcase--) {
        char buf[30] = {};
        fgets(buf, 30, stdin);
        char s_num[2][6] = {};
        char s_result[11] = {};
        char op;
        sscanf(buf, "%s %c %s = %s\n", s_num[0], &op, s_num[1], s_result);
        
        int num1 = string_to_num(s_num[0]);
        int num2 = string_to_num(s_num[1]);
        int result;
        switch(op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;            
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }
        
        //printf("%s %c %s = %s\n", s_num[0], operator, s_num[1], s_result);
        //printf("%d %c %d = %d\n", num1, operator, num2, result);
        if(check_num_string(s_result, result)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    
    }
    return 0;
}

int check_num_string(char *str, int result) {
    if(result < 0 || result >=10) return 0;
    int str_len = strlen(str);
    int i;
    switch(result) {
        case 1:
            if(str_len != 3) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[1][str[i]-'a'])
                    return 0;
            }
            break;
        case 2:
            if(str_len != 3) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[2][str[i]-'a'])
                    return 0;
            }
            break;
        case 3:
            if(str_len != 5) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[3][str[i]-'a'])
                    return 0;
            }
            break;
        case 4:
            if(str_len != 4) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[4][str[i]-'a'])
                    return 0;
            }
            break;
        case 5:
            if(str_len != 4) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[5][str[i]-'a']) {

                    return 0;
                }
            }
            break;
        case 6:
            if(str_len != 3) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[6][str[i]-'a'])
                    return 0;
            }
            break;
        case 7:
            if(str_len != 5) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[7][str[i]-'a'])
                    return 0;
            }
            break;
        case 8:
            if(str_len != 5) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[8][str[i]-'a'])
                    return 0;
            }
            break;
        case 9:
            if(str_len != 4) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[9][str[i]-'a'])
                    return 0;
            }
            break;
        case 0:
            if(str_len != 4) return 0;
            for(i=0;i<str_len;i++) {
                if(!num_map[0][str[i]-'a'])
                    return 0;
            }
            break;
    }

    return 1;
}

int string_to_num(char *str) {
    if(strcmp(str, "one")==0)
        return 1;
    else if(strcmp(str, "two")==0)
        return 2;
    else if(strcmp(str, "three")==0)
        return 3;
    else if(strcmp(str, "four")==0)
        return 4;
    else if(strcmp(str, "five")==0)
        return 5;
    else if(strcmp(str, "six")==0)
        return 6;
    else if(strcmp(str, "seven")==0)
        return 7;
    else if(strcmp(str, "eight")==0)
        return 8;
    else if(strcmp(str, "nine")==0)
        return 9;
    else if(strcmp(str, "zero")==0)
        return 0;


    return 0;
}


void init_num_map() {
    num_map[0]['z'-'a'] = 1;
    num_map[0]['e'-'a'] = 1;
    num_map[0]['r'-'a'] = 1;
    num_map[0]['o'-'a'] = 1;
    num_map[1]['o'-'a'] = 1;
    num_map[1]['n'-'a'] = 1;
    num_map[1]['e'-'a'] = 1;
    num_map[2]['t'-'a'] = 1;
    num_map[2]['w'-'a'] = 1;
    num_map[2]['o'-'a'] = 1;
    num_map[3]['t'-'a'] = 1;
    num_map[3]['h'-'a'] = 1;
    num_map[3]['r'-'a'] = 1;
    num_map[3]['e'-'a'] = 1;
    num_map[3]['e'-'a'] = 1;
    num_map[4]['f'-'a'] = 1;
    num_map[4]['o'-'a'] = 1;
    num_map[4]['u'-'a'] = 1;
    num_map[4]['r'-'a'] = 1;

    num_map[5]['f'-'a'] = 1;
    num_map[5]['i'-'a'] = 1;
    num_map[5]['v'-'a'] = 1;
    num_map[5]['e'-'a'] = 1;
    num_map[6]['s'-'a'] = 1;
    num_map[6]['i'-'a'] = 1;
    num_map[6]['x'-'a'] = 1;
    num_map[7]['s'-'a'] = 1;
    num_map[7]['e'-'a'] = 1;
    num_map[7]['v'-'a'] = 1;
    num_map[7]['e'-'a'] = 1;
    num_map[7]['n'-'a'] = 1;
    num_map[8]['e'-'a'] = 1;
    num_map[8]['i'-'a'] = 1;
    num_map[8]['g'-'a'] = 1;
    num_map[8]['h'-'a'] = 1;
    num_map[8]['t'-'a'] = 1;
    num_map[9]['n'-'a'] = 1;
    num_map[9]['i'-'a'] = 1;
    num_map[9]['n'-'a'] = 1;
    num_map[9]['e'-'a'] = 1;
}
