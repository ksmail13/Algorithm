#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 20

#define SWAP(a,b,t) (t)=(a);(a)=(b);(b)=(t)

int arr[ARR_SIZE];


void print_arr(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d\t", arr[i]);
    }
    putchar('\n');
}

void q_sort(int *arr, int left, int right) {
    int pivot = arr[left];
    int front = left, rear = right+1;
    int temp;
    
    if (left >= right) return ;

    while(front < rear) {
        do{
        //    printf("front : %d\n", front+1);
        }while(arr[++front] < pivot && front < right); 
        do{
        //    printf("end : %d\n", rear-1);
        }while(arr[--rear] >= pivot && rear >left); 
        if(front < rear) {
        //    printf("arr[%d] = %d <-> arr[%d] = %d\n", front, arr[front], rear, arr[rear]);
            SWAP(arr[front], arr[rear], temp);
            print_arr(arr, ARR_SIZE);
        }
    }
    SWAP(arr[rear], arr[left], temp);
    print_arr(arr, ARR_SIZE);

    q_sort(arr, left, rear);
    q_sort(arr, rear+1, right);
}

int main() {
    int i;
    for(i=0;i<ARR_SIZE;i++) {
        arr[i] = random()%ARR_SIZE;
    }

    print_arr(arr, ARR_SIZE);
    q_sort(arr, 0, ARR_SIZE-1);

    print_arr(arr, ARR_SIZE);
    return 0;
}
