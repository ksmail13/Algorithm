#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define LIMIT 10000

using namespace std;

// pair (거리, 종점)
vector<vector<pair<double, int> > > m;
int n;
double find(int src) {
    vector<double> dist(n, 100000);
    dist[src]=0.0;
    priority_queue<pair<double, int> > q;

    q.push(make_pair(0.0, src));

    while(!q.empty()) {
        double cost = -q.top().first;
        double curr = q.top().second;
        q.pop();
        if(cost > dist[curr]) {
            continue;
        }

        for(int i=0;i<m[curr].size();i++) {
            int target = m[curr][i].second;
            double nextcost = log(cost) + log(m[curr][i].first);

            if(dist[target] > nextcost) {
                dist[target] = nextcost;
                q.push(make_pair(-nextcost, target));
            }
        }

    }

    return dist[n-1];
}

int main() {
    int tcase;
    cin >> tcase;
    while(tcase--) {
        int M;

        cin >> n >> M;
        m.resize(n);
        for(int i=0;i<M;i++) {
            int start, end;
            double rate;

            cin >> start >> end >> rate;

            m[start].push_back(make_pair(rate, end));
        }

        cout << find(0) << endl;

    }

    return 0;
}
