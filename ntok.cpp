#include <iostream>
#include <cstring>

#define LIMIT 1000000
using namespace std;

long long strTo10Num(const char *strnum, int n);
void numToKStr(long long num, int k, bool isMinus);

char numToChar(int num);

int main() {
    int testcase;
    cin >> testcase;
    
    while(testcase--) {
        char strnum[LIMIT] = {};
        int n, k;
        bool isMinus = false;
        cin >> strnum;
        cin >> n >> k;
        if(!strcmp(strnum, "0")) {
            cout << "0" <<endl;
        } else {
            if(strnum[0] == '-')
                isMinus = true;
                
            long long num = strTo10Num(strnum, n);
            numToKStr(num, k, isMinus);
        }
    }
    
    return 0;
}


long long strTo10Num(const char *strnum, int n)
{
    long long result = 0;
    long basic = 1;
    
    int length = strlen(strnum);
    
    for(int i=length-1;i>=0;i--) {
        int jarit = strnum[i];
        if(jarit == '-')
            continue;
        if(jarit >= '0' && jarit <= '9')
            result += ((jarit-'0')*basic);
        else if(jarit >= 'A' && jarit <= 'Z')
            result += ((jarit-'A'+10)*basic);
        else if(jarit >= 'a' && jarit <= 'z')
            result += ((jarit-'a'+10)*basic);
        
        basic *= n;
    }
    
    return result;
}

void numToKStr(long long num, int k, bool isMinus) {
    char result[LIMIT];
    int index=0;
    
    if(k==10) {
        cout << num << endl;
        return;
    }
        
    while(num) {
        result[index++] = numToChar(num%k);
        num /= k;
    }
    
    if(isMinus)
        cout << '-';
    while(index-->0) {
        cout << result[index];
    }
    cout << endl;
}


char numToChar(int num) {
    if(num<=9)
        return num+'0';
    else
        return num-10+'A';
}