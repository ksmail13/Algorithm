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
    if(m-2>=0) t = m-2;
    else t = n+m-2;

    q[t].node = q[m-1].node;

    while(pq) {
        if(pq->node == pq) break;
        cout << " ";
        for(i=0;i<k && pq != pq->node;i++) {
            bpq = pq;
            pq = pq->node;
        }


        if(!chk[pq->data-1]) {
            chk[pq->data-1] = 1;
            cout << pq->data;
            bpq->node = pq->node;

        }
        else {
            pq = NULL;
        }
    }
    cout << endl;

    return 0;
}
