#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

QueueNode* q[10];
QueueNode* back[10];

int digit(int x, int m) {
    return x % (10 * m) / m;
}

void radixsort(int* a, int n) {
    int m = a[0];
    for(int i=0; i<n; i++) if(a[i] > m) m = a[i];
    int k = 0;
    for(; m; m/=10) k++;

    m = 1;
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) enQueue(&q[digit(a[j], m)], &back[digit(a[j], m)], a[j]);
        for(int j=0, l=0; j<10; j++) {
            while(!is_queue_empty(q[j])) a[l++] = deQueue(&q[j], &back[j]);
        }
        m *= 10;
    }
}

int main() {
    int a[10] = {10, 40, 29, 18, 57, 13, 56, 21, 17, 64};
    radixsort(a, 10);
    for(int i=0; i<10; i++) printf("%d ", a[i]);
}

