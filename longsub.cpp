#include <iostream>
#include <cstring>
#define LIMIT 1000
using namespace std;

int bignumcmp(char *num1, char *num2);
char *sub(char *num1, char *num2, char *result);

int main() {
    int testcase;
//    cin >> testcase;
//    while(testcase--) {
        char num1[LIMIT]={};
        char num2[LIMIT]={};
        char result[LIMIT]={};
        int num1len, num2len; 
        int isMinus = 0;
        int trim = 1;
        cin >> num1 >> num2;
        
        num1len = strlen(num1);
        num2len = strlen(num2);
        if (bignumcmp(num1, num2) == -1) {
            isMinus = 1;
            sub(num2, num1, result);
        }
        else {
            sub(num1, num2, result);
        }
            
        if(isMinus)
            cout << '-';
        for(int i = strlen(result); i>=0;i--){
            if(result[i] == '\0' || (trim && result[i] == '0')) continue;
            //cout << result[i];
            trim = 0;
            printf("%d", result[i] - '0');
        }
        // 어떤 숫자도 표시되지 않았으므로 결과가 0이라는 뜻
        if(trim) printf("0");
        
    //}
    
    return 0;
}

int bignumcmp(char *num1, char *num2) {
    int num1len = strlen(num1);
    int num2len = strlen(num2);
    
    if(num1len > num2len)
        return 1;
    else if(num1len < num2len)
        return -1;
    else {
        for(int i=0;i<num1len ;i++) {
            if(num1[i] > num2[i])
                return 1;
            else if(num1[i] < num2[i])
                return -1;
        }
        
        return 0;
    }
}

char *sub(char *num1, char *num2, char *result) {
    int num1len = strlen(num1), num2len = strlen(num2);
    char num1rev[LIMIT], num2rev[LIMIT];
    int j = 1, i;
    
    cout << endl << num1 << endl << num2 << endl;
    
    // 뒤집기
    for(i=num1len-1;i>=0;i--) {
        num1rev[num1len-i-1] = num1[i];
    }
    num1rev[num1len] = '\0';
    
    for(i=num2len-1;i>=0;i--) {
        num2rev[num2len-i-1] = num2[i];
    } 
    num2rev[num2len] = '\0'; 
    
    for(i=0;i<num2len;i++) {
        int resultNum = (num1rev[i]-'0')-(num2rev[i]-'0');
        if(resultNum>=0)
            result[i] = (resultNum)+'0';
        else {
            result[i] = (resultNum+10)+'0';
            j=1;
            while((num1rev[i+j]-'0') == 0) {
                j++;
            }
            num1rev[i+j]--;
            while(--j) {
                num1rev[i+j] = '9';
            }
        }
    }
    for(;i<=num1len+1;i++) {
        result[i] = num1rev[i];
    }

    return result;
}