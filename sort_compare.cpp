#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LIMIT 10

using namespace std;


void quicksort(int *arr, int left, int right);
void printarr(int *arr, int len);

int main(int argc, char *argv[]) {
    int arr[LIMIT];
    
    for(int i=0;i<LIMIT;i++) {
        arr[i] = rand()%LIMIT;
    }

    printarr(arr, LIMIT);
    
    quicksort(arr, 0, LIMIT-1);
    
    printarr(arr, LIMIT);
    return 0;
}

void swap(int *a, int *b)
{
    cout << "swap " << *a << " " << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *arr, int left, int right) {
    if(!arr || (left >= right)) return ;
    int start = left, end = right++;
    int pivot = arr[start];
    cout << "start left->" << left << " right->" << right << endl;
    do {
        while(left <= end && arr[++left] < pivot) {}
        while(right > start && arr[--right] > pivot) {}
        
        cout << "left : " << left << " right:" << right << endl;
		if(left < right)
        	swap(&arr[left], &arr[right]);
    } while(left < right) ;
    
    cout << "start : " << start << " right:" << right << endl;
    swap(&arr[start], &arr[right]);
    cout << "left sort" << endl;
	if(right != end)
    	quicksort(arr, start, right);
    cout << "right sort" << endl;
	if(right+1 != start)
    quicksort(arr, right+1,end);
}

void printarr(int *arr, int len) {
    if(!arr) return;
	for(int i=0;i<len;i++) {
        printf("%d ",i);
    }
	putchar('\n');
    for(int i=0;i<len;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
