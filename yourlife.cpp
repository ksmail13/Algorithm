#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int> > g;
int find(int n){
    vector<int> dist(n+1, 0x7fffffff);
    dist[1] = 0;
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty() ) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(cost > dist[here]) {
            continue;
        }

        for(int i=0;i<g[here].size();i++) {
            int there = g[here][i];
            int ndist = cost+1;

            if(dist[there] > ndist) {
                dist[there] = ndist;
                pq.push(make_pair(-ndist, there));
            }
        }
    }

    return dist[n];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n==1) {
        printf("0\n");
        return 0;
    }
    g.resize(n+1);
    // make graph
    for (int i=m;i!=0;i--) {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
    }
    // find solution
    int result = find(n);
    if(result == 0x7fffffff){
        printf("-1\n");
    }
    else {
        printf("%d\n",result);
    }
    
    return 0;   
}
