#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LIMIT 100000

using namespace std;

struct queue {
    int data;
    struct queue *node;
};


int main() {
    int test_case;
    cin >> test_case;
    while(test_case--) {
        
        int chk[LIMIT]={};
        int n, m, k, i, t;
        int curr, cnt = 0;
        cin >> n >> m >> k;
        
        struct queue q[LIMIT]={};
        struct queue *pq, *bpq;
        for(i=1;i<n+1;i++) {
            q[i-1].data = i;
            t = (i)%n;
            q[i-1].node = &q[t];
            
        }
        
        cout << q[m-1].data;
        pq = &q[m-1];
        chk[m-1] = 1;
//        t=((m-2>=0)?(m-2):((n-1)+(m-2)));
        if(m-2>=0) t = m-2;
        else t = n+m-2;
        //cout << endl << "connect" << t << " " << m%n << endl;
        
//        printf("%d %d", q[t].node, q[m-1].node);
        q[t].node = q[m-1].node;
        
        while(pq) {
            if(pq->node == pq) break;
            cout << " ";
            for(i=0;i<k && pq != pq->node;i++) {
                bpq = pq;
                pq = pq->node;
                //cout << "curr data" << pq->data << endl;
            }
            
            
            if(!chk[pq->data-1]) {
                chk[pq->data-1] = 1;
                cout << pq->data;
                bpq->node = pq->node;
                
//                cout << "data " << bpq->data << " connect with " << pq->node->data << endl;
            }
            else {
//                cout << "data " << pq->data << "is checked " << endl;
                pq = NULL;
            }
        }
        /*
         cout << endl;
         memset(chk, 0, sizeof(chk));
         
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
        */
        cout << endl;
    }
    
    return 0;
}
