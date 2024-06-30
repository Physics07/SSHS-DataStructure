#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void make_heap(int* a, int curr, int n) {
    int x = a[curr];
    int j;
    for(j=curr*2; j<=n; j<<=1) {
        if(j < n) if(a[j] < a[j+1]) j++;
        if(a[curr] >= a[j]) break;
        a[j>>1] = a[j];
    }
    a[j>>1] = x;
}

void heapsort(int* a, int n) {
    for(int i=n/2; i>0; i--) make_heap(a, i, n);
    for(int i=n-1; i>0; i--) {
        swap(&a[1], &a[i+1]);
        make_heap(a, 1, i);
    }
}

int main() {
    int a[11] = {0, 10, 9, 8, 2, 5, 3, 6, 1, 7, 4}; // 1-based array
    heapsort(a, 10);
    for(int i=0; i<10; i++) printf("%d ", a[i]);
}