#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>

#define RIGHT_LIMIT(right) (((right)>=LIMIT) ? LIMIT : (right))
#define LIMIT 200

using namespace std;


void quicksort(int *arr, int left, int right);
void mergesort(int *arr, int length);
void printarr(int *arr, int len);

int main(int argc, char *argv[]) {
    int arr[LIMIT];
    int arr2[LIMIT];
    clock_t start;
    for(int i=0;i<LIMIT;i++) {
//        arr[i] = LIMIT-i-1;
        arr[i] = rand()%10;
        arr2[i] = arr[i];
    }
    
    printf("before\n");
    printarr(arr, LIMIT);
    
    printf("after Quicksort\n");
    start = clock();
    quicksort(arr, 0, LIMIT-1);
    printarr(arr, LIMIT);
    printf("Quick sort time : %lf sec\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
    
    printf("after Merge sort\n");
    start = clock();
    mergesort(arr2, LIMIT);
    printarr(arr2, LIMIT);
    printf("Merge sort time : %lf sec\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}

void swap(int *a, int *b)
{
//    cout << "swap " << *a << " " << *b << endl;
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
    } while(left < right);
    
//    cout << "start : " << start << " right:" << right << endl;
    swap(&arr[start], &arr[right]);
    
//    cout << "left sort" << endl;
	quicksort(arr, start, right);

//    cout << "right sort" << endl;
    quicksort(arr, right+1,end);
}

// not complete
void mergesort(int *arr, int length) {
    if(!arr) return;
    int *original = arr;
    int *created = (int *)calloc(length, sizeof(int));
    int *arr2 = created;
    int *temp;
    int unit=1;
    int left=0, right=1, i, k=0;
    int changed = 0;
    
    while(unit < length) {
//        cout << "unit:" << unit << endl;
        while(left < length && right < length) {
            int right_temp = right;
//            cout << "before left:"<< left << " right:" << right << endl;
            for (i=0;i<unit*2;i++) {}
            for(i=left;i<left+unit;) {
                if(arr[i] <= arr[right_temp] || right_temp >= RIGHT_LIMIT(right+unit)) {
                    arr2[k++] = arr[i++];
                }
                else if(arr[i] > arr[right_temp]) {
                    arr2[k++] = arr[right_temp++];
                }
            }
            for(i=right_temp;i<RIGHT_LIMIT(right+unit);i++) {
                arr2[k++] = arr[i];
            }
            
//            printarr(arr2, LIMIT);
//            cout << "after  left:"<< left << " right:" << right << endl;
            left = right + unit;
            right = left + unit;
        }
        
        temp = arr;
        arr = arr2;
        arr2 = temp;
        changed = changed ^ 0x1;
        unit *= 2;
        left = 0;
        right = unit;
        k=0;
    }
    
    if(changed) {
        for(int i=0;i<length;i++) 
            original[i] = created[i];
    }
    free(created);
}

void printarr(int *arr, int len) {
    if(!arr) return;
	for(int i=0;i<len;i++) {
        printf("%d ",i);
    }
	putchar('\n');
    printf("--------------------\n");
    for(int i=0;i<len;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
