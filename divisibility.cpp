#include <iostream>
#include <cstdio>
#include <cstring>
#define LIMIT 10001
#define DIV 61
#define JARIT 62

using namespace std;

int char_to_num(char c) {
    if(c >= '0' && c <='9'){
       return c-'0';
    }
    else if(c >= 'A' && c <= 'Z') {
        return c-'A'+10;
    }
    else {
        return c-'a'+36;
    }
}

int main() {

    while(true) {
        char buf[LIMIT];
        scanf("%s", buf);
        long long t = 0;
        if(strcmp(buf, "end")==0) break;

        for(int i=strlen(buf);i>=0;i--) {
            int num = char_to_num(buf[i]);

            t = ((t%DIV * JARIT%DIV)%DIV + num%DIV) % DIV;
        }

        if(t == 0)
            printf("yes\n");
        else
            printf("no\n");

    }

    return 0;
}

