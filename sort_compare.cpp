#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>

#define LIMIT 10

using namespace std;


void quicksort(int *arr, int left, int right);
void mergesort(int *arr, int length, int unit);
void printarr(int *arr, int len);

int main(int argc, char *argv[]) {
    int arr[LIMIT];
    int arr2[LIMIT];
    clock_t start;
    for(int i=0;i<LIMIT;i++) {
        arr[i] = rand()%LIMIT;
    }
    // duplicate array
    memcpy(arr2, arr, LIMIT);

    printf("before\n");
    printarr(arr, LIMIT);
    
    printf("after Quicksort\n");
    start = clock();
    quicksort(arr, 0, LIMIT-1);
    printarr(arr, LIMIT);
    printf("Quick sort time : %lf sec\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
    
    printf("after Merge sort\n");
    start = clock();
    mergesort(arr2, LIMIT, 2);
    printf("Merge sort time : %lf sec\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
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
//    cout << "start left->" << left << " right->" << right << endl;
    do {
        while(left <= end && arr[++left] <= pivot) {}
        while(right > start && arr[--right] >= pivot) {}
        
//        cout << "left : " << left << " right:" << right << endl;
		if(left < right)
        	swap(&arr[left], &arr[right]);
    } while(left < right) ;
    
//    cout << "start : " << start << " right:" << right << endl;
    swap(&arr[start], &arr[right]);
//    cout << "left sort" << endl;
	if(right != end)
    	quicksort(arr, start, right);
//    cout << "right sort" << endl;
	if(right+1 != start)
    quicksort(arr, right+1,end);
}

void mergesort(int *arr, int length) {
    if(!arr || length) return;
    
    int *arr2 = (int *)malloc(sizeof(int)*length);
    int *temp;
    int unit=1;
    int left=0, right=1, i, k=0, temp;
    
    while(unit > length) {
        while(left < length) {
            for (i=0;i<unit*2;i++) {
                if(arr[left] < arr[right]) {
                    arr2[k++] = arr[left];
                    left++;
                }
				else if(arr[left] > arr[right] ) {

				}
            }
        }
    }
    
    free(arr2);
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
