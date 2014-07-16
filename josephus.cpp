#include <iostream>

#define LIMIT 1000

using namespace std;


int main(int argc, char *argv[]) {
    int chk[1000]={};
    int n, m, k, i;
    int curr, cnt = 0;
    cin >> n >> m >> k;
    
    m = m - 1;
    chk[m] = 1;
    cnt++;
    curr = m;
    cout << curr+1 << " ";
    while(cnt != n) {
        
        for(i=0;i<k;i++) {
            
            curr +=1;
            curr %= n;
            while(chk[curr]){
                curr +=1;
                curr %= n;                
            }
        }
        //cout << curr+1 << endl;
        if(!chk[curr]) {
            chk[curr] = 1;
            cnt+=1;
            cout << curr+1 << " ";
        }
    }
    
    
    return 0;
}
