#include <iostream>
#include <cstring>
#define LIMIT 1000

using namespace std;

int main(int argc, char *argv[]) {
    int endblock = 0;
    while(1) {
        int coach_cnt;
        //cout << "coach_cnt : ";
        cin >> coach_cnt;
        while(coach_cnt) {
            int require_coach = coach_cnt;
            int cross[LIMIT] = {};
            int cross_idx = 0;
            int coach[LIMIT], stop = 0;
            
            for(int i=0;i<coach_cnt;i++) {
                //cout << "coach"<<i <<" : ";
                cin >> coach[i];
                if(coach[i] == 0) {
                    stop = 1;
                    break;
                }
            }
            if(!stop){
                int error=0;
                
                for(int i=0;i<coach_cnt;i++) {
                    if(coach[i] != require_coach) {
                        if(cross[cross_idx] != 0 && coach[i] > cross[cross_idx-1]) {
                            //cout << coach[i] << " " << cross[cross_idx] << endl;
                            cout << "NO" << endl;
                            error = 1;
                            break;
                        }
                        else {
                            cross[cross_idx++] = coach[i];
                        }
                    }
                    else {
                        require_coach--;
                    }
                }
                memset(cross, 0, sizeof(cross));
                cross_idx = 0;
                
                for(int i=0;i<coach_cnt;i++) {
                    if(coach[i] != require_coach) {
                        if(cross[cross_idx] != 0 && coach[i] < cross[cross_idx-1]) {
                            //cout << coach[i] << " " << cross[cross_idx] << endl;
                            cout << "NO" << endl;
                            error = 1;
                            break;
                        }
                        else {
                            cross[cross_idx++] = coach[i];
                        }
                    }
                    else {
                        require_coach--;
                    }
                }

                if(!error)
                    cout << "YES" << endl;
            }
            else {
                cout << endl;
                break;
            }
        }
        
        if(!coach_cnt) {
            return 0;
        }
        else {
            endblock = 0;
        }
    }
    
    return 0;
}