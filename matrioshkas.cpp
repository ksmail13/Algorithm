#include <iostream>
#include <cstdio>
#include <cstring>

#define LIMIT 20000
using namespace std;

struct numinfo {
    long long num;
    long long size;
    int minus;
};

long long abs(long long data)
{
    if(data < 0)
        return data*-1;
    else
        return data;
}

int main(int argc, char *argv[]) {
//    char buf[LIMIT] = {};
//    fgets(buf, LIMIT, stdin);
//    while(strlen(buf)) {
        struct numinfo s[LIMIT]={};
        int s_idx=0;
        long long temp=0;
        int error;
        do{
            cin >> temp;
//            sscanf(buf, "%d", &temp);
//            cout << buf <<  " " <<temp << endl;
//            printf("%d\n", __LINE__);
            if(temp < 0) {
                s[s_idx].num = abs(temp);
                s[s_idx].minus = 1;

                if(s_idx > 0 && s[s_idx-1].num < abs(temp)) {
                    //printf("%d : %d %lld %lld\n", __LINE__, s_idx-1, s[s_idx-1].num, temp);
                    error = 1;
                }
                s_idx++;
            }
            else {
                s_idx--;
                //printf("%d : %lld %lld\n", __LINE__, s[s_idx].num, temp);
                
                if(s[s_idx].minus == 1){
                    if(s[s_idx].num != temp)
                        error = 1;
                    else if(s_idx>0){
                        s[s_idx-1].size += temp;
                        if(s[s_idx-1].num <= s[s_idx-1].size)
                            error = 1;
                    }
                }
            }
            
        } while(s_idx);
        
        if(error)
            printf(":-( Try again.");
        else
            printf(":-) Matrioshka!");
        
        
//        fgets(buf, LIMIT, stdin);
//    }
    
    return 0;
}