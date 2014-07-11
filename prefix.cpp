#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LIMIT 10000
#define ISOPTOR(x) (x) == '+'||(x) == '-'||(x) == '*'||(x) == '/'

using namespace std;
int main() {
    int testcase;
    cin >> testcase;
    while(testcase--) {
        char evaluation[LIMIT];
        int result=0, len;
        char optorbuf[LIMIT];
        int optorIdx=0;
        int oprnd1=-1;
        int isDivideZero = 0;
        cin >> evaluation;
        
        len = strlen(evaluation);
        for(int i=0;i<len && !isDivideZero;i++) {
            if(ISOPTOR(evaluation[i])) {
                optorbuf[optorIdx++] = evaluation[i];
            }
            else{
                if(i-optorIdx==0)
                    result = evaluation[i]-'0';
                else
                    oprnd1 = evaluation[i]-'0';
            
                //cout << result << " " << oprnd1 << " " << optorbuf[optorIdx-1]<< endl;
                if(oprnd1 != -1)
                {
                    switch(optorbuf[--optorIdx]) {
                        case '+':
                        result += oprnd1;
                        break;
                        case '-':
                        result -= oprnd1;
                        break;
                        case '*':
                        result *= oprnd1;
                        break;
                        case '/':
                        if(oprnd1 == 0) {
                            isDivideZero = 1;
                        }else {
                            result /= oprnd1;
                        }
                        break;
                    }
                }
            }
        }
        if(!isDivideZero)
            cout << result << endl;
        else
            cout << "Divide by zero" << endl;
        
    }

    return 0;
}