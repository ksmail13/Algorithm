#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<vector<int> > dg;
vector<bool> visit;
int cnt=0;
int floyd(int n) {
    for(int k=1;k<n;k++) {
        for(int i=1;i<n;i++) {
            for(int j=1;j<n;j++) {
                if(dg[i][j] > dg[i][k] + dg[k][j]) {
                    dg[i][j] = dg[i][k] + dg[k][j];
                }
            }
        }
    }

    return 0;
}

int find(int n, int curr, int end) {
    if(curr == end) {
        cnt++;
        return 0;
    }
    
    if(visit[curr]){
        return 0;
    }

    for(int i=0;i<n;i++) {
        visit[curr] = true;
        if(visit[i]==false)
            find(n, i, end);
    }

    return 0;
}

int main() {
    int tcase;

    cin >> tcase;

    while(tcase--) {
        int n, m, q;

        cin >> n >> m >> q;
        g.resize(n+1);
        dg.resize(n+1);
        for(int i=1;i<=n;i++) {
            g[i].clear();
            g[i].resize(n);
            dg[i].clear();
            dg[i].resize(n, 9999999);
        }
        visit.clear();
        cnt = 0;
        for(int i=1;i<=m;i++) {
            int a,b, d;
            cin >> a >>b >> d;

            g[a][b] = d;
        }
        
        floyd(n);

        for(int i=0;i<q;i++) {
            int a,b;
            cin >> a >> b;
            cnt =0;
            
        }

    }
    return 0;
}
