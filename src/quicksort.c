#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int* a, int s, int e) {
    if(s > e) return;
    if(s == e) return;
    if(s == e - 1) {
        if(a[s] > a[e]) swap(&a[s], &a[e]);
        return;
    }
    int pivot = s;
    int l = s + 1, r = e;
    while(l < r) {
        while(l <= r && a[l] < a[pivot]) l++;
        while(l <= r && a[r] >= a[pivot]) r--;
        if(l >= r) break;
        swap(&a[l], &a[r]);
        l++, r--;
    }
    swap(&a[r], &a[pivot]);
    quicksort(a, s, r-1);
    quicksort(a, r+1, e);
}

int main() {
    int a[10] = {10, 9, 8, 2, 5, 3, 6, 1, 7, 4};
    quicksort(a, 0, 9);
    for(int i=0; i<10; i++) printf("%d ", a[i]);
}