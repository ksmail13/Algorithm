#include <iostream>
#define LIMIT 1000000

using namespace std;

class Ant
{
public:
    int pos;
    int dir;
    void move() {
        pos += dir;
    }
}

void check(Ant *postionarr);

int main(int argc, char *argv[]) {
    int testcase;
    cin >> testcase;
    while(testcase--) {
        int linelength, antcnt;
        cin >> linelength >> antcnt;
        
        Ant antposition[LIMIT] = {};
        for(int i=0;i<antcnt;i++) {
            cin >> antposition[i].pos;
        }
        
        check(antposition);
    }
}

void check(Ant *antPos) {
    
}