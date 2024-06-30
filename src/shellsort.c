#include <stdio.h>
#include <stdlib.h>

void interval(int* a, int s, int e, int h) {
    for(int i=s+h; i<e; i+=h) {
        int curr = a[i];
        int j;
        for(j=i-h; j>=s && a[j] > curr; j-=h) {
            a[j+h] = a[j];
        }
        a[j+h] = curr;
    }
}

void shellsort(int* a, int n) {
    for(int i=n/2; i; i>>=1) {
        for(int j=0; j<i; j++) {
            interval(a, j, n, i);
        }
    }
}

int main() {
    int a[10] = {10, 9, 8, 2, 5, 3, 6, 1, 7, 4};
    shellsort(a, 10);
    for(int i=0; i<10; i++) printf("%d ", a[i]);
}