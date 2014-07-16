#include <iostream>
#include <cstdio>
#include <cstring>
#define LIMIT 200
using namespace std;

struct parentheses {
    char type;
    int open;
};

int main(int argc, char *argv[]) {
    int test_case;
    scanf("%d", &test_case);
    getchar();
    while(test_case--) {
        struct parentheses s[LIMIT] = {};
        int s_idx=0;
        char buf[LIMIT]={};
        int buflen=0;
        int error=0;
        fgets(buf, LIMIT, stdin);
        //scanf("%s", &buf);
        buflen = strlen(buf);
        
        for(int i=0;i<buflen;i++) {
            if(error) break;
            
            if(i==0 && (buf[i] == ']' || buf[i] == ')')) {
                error = 1;
            }
            else if(buf[i] == '(' || buf[i] == '[') {
                s[s_idx].type = buf[i];
                s[s_idx].open = 1;
                s_idx++;
            }
            else if(buf[i] == ')') {
                s_idx--;
                if(s[s_idx].type != '(') {
                    error = 1;
                }
            }
            else if(buf[i] == ']') {
                s_idx--;
                if(s[s_idx].type != '[') {
                    error = 1;
                }
            }   
        }
        
        if((!error && !s_idx) || !buflen) {
//            cout <<  "YES" << endl;
            printf("Yes");
        } else {
//            cout << error << " " << s_idx << endl;
            printf("No");
        }
    }
    
    return 0;
}