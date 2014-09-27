#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
vector<vector<set<string> > > map;

vector<string> word_route;

int search(char start) {
    //int start = s[0]-'a';
    cout << "search start by "<< (char)start << endl; 
    for(int i=0;i<26;i++) {
        cout << "Start " << start << " i " << i << " emtpy " << map[(int)start][i].empty() << endl;
        if(map[start][i].empty()) continue;
        set<string>::iterator item = map[start][i].begin();
        word_route.push_back(*item);
        map[start][i].erase(item);
        search((*item)[(*item).length()-1]);
    }

    return 0;
}

int main() {
    int tcase;
    cin >> tcase;
    map.resize(26);
    for(int i=0;i<26;i++) {
        map[i].resize(26);
    }
    while(tcase--) {
        int n;
        string s;
        set<string> i_set;
        bool error = false;
        for(int i=0;i<map.size();i++) {
            for(int j=0;j<map[i].size();j++) {
                map[i].clear();
            }
        }
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> s;
            int start = s[0]-'a';
            int end = s[s.length()-1] - 'a';
            
            map[start][end].insert(s);
        }
        cout << "search start" << endl;
        // 한번에 소거되어야 하므로
        search(s[0]);
        
        
        for(vector<vector<set<string> > >::iterator it = map.begin();
                it != map.end();
                it++) {
            for(vector<set<string> >::iterator iit = it->begin();iit != it->end();iit++) {
                if(!iit->empty()) {
                    error = true;
                }
            }
        }

        if(error) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            for(vector<string>::iterator it = word_route.begin();it!=word_route.end();it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
