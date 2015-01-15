#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


void inittrain(vector<string> &vs) 
{
    vs.clear();
    vs.push_back("1010");
    vs.push_back("1020");
    vs.push_back("1030");
    vs.push_back("1040");
    vs.push_back("1050");

}

void passA(vector<string> &vs)
{
    string temp = vs[vs.size()-1];
    vs[vs.size()-1] = vs[0];
    vs[0] = temp;

    vs.push_back("Angel");
}

void passB(vector<string> &vs)
{
    vs.insert(vs.begin(),"Bee");
}

void passC(vector<string> &vs)
{
    vs.pop_back();
    vs.insert(vs.begin(),"Cream");
}

void passD(vector<string> &vs)
{
    vs.erase(vs.begin());
    vs.push_back("Developer");
}

void passE(vector<string> &vs)
{
    vs.insert(vs.begin(),"Engineer");
    vs.push_back("Engineer");
}



int main()
{
    vector<string> vs;

    int tcase, ccase, i;
    char c;
    scanf("%d", &tcase);
    ccase = tcase;
    while(ccase--) {
        inittrain(vs);
        
        do {
            switch(c=getchar()) {
                case 'A':
                    passA(vs);
                    break;
                case 'B':
                    passB(vs);
                    break;
                case 'C':
                    passC(vs);
                    break;
                case 'D':
                    passD(vs);
                    break;
                case 'E':
                    passE(vs);
                    break;
            }

        } while(c != '0');

        for(i=0;i<vs.size();i++) {
            printf("%s\n", vs[i].c_str());
        }
    }
    return 0;
}
