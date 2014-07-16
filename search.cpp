#include <iostream>
#include <cstdio>
#define LIMIT 10
using namespace std;

typedef int datatype;

int linear_search(datatype *arr, int len, datatype search);

int main(int argc, char *argv[]) {
    datatype arr[LIMIT] = {10,9,8,7,6,5,4,3,2,1};
    datatype search;
    
    cin >> search;
    
    printf("%d in %d", search, linear_search(arr, LIMIT, search));
    
    return 0;
}


int linear_search(datatype *arr, int len, datatype search) {
    int i=0;
    for(i=0;i<len;i++) {
        if(arr[i] == search) {
            return i;
        }
    }
    return -1;
}