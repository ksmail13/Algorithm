#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define LIMIT 10001

using namespace std;

int main() 
{
    vector<char> cv;
    int tcase, i, cursor=0;
    scanf("%d", &tcase);
    getchar();

    while(tcase--) {
        char buf[LIMIT];
        int buflen;
        fgets(buf, sizeof(buf), stdin);
        cursor=0; 
        buflen = strlen(buf);
        buf[buflen-1] = '\0';
        for(i=0;i<buflen;i++) {
            switch(buf[i]) {
                case '[':
                    cursor=0;
                    break;
                case ']':
                    cursor=cv.size();
                    break;
                default:
                    cv.insert(cv.begin()+cursor++, buf[i]);
                    break;
            }
        }

        for(vector<char>::iterator it = cv.begin();it != cv.end(); it++) {
            printf("%c",*it);
        }
        putchar('\n');
        cv.clear();
    }
}
