#include <stdio.h>
#include <stdlib.h>

int heap[1001];
int sz;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    heap[++sz] = x;
    for(int curr=sz; curr>1; curr>>=1) {
        if(heap[curr] > heap[curr>>1]) swap(&heap[curr], &heap[curr>>1]);
        else break;
    }
}

int delete() {
    if(sz == 0) exit(1);
    int ret = heap[1];
    heap[1] = heap[sz--];
    for(int curr=1; 2*curr<=sz;) {
        int l = curr << 1;
        int r = curr << 1 | 1;
        if(heap[l] < heap[r]) swap(&l, &r);
        if(heap[curr] < heap[l]) {
            swap(&heap[l], &heap[curr]);
            curr = l;
        }
        else break;
    }
    return ret;
}

int top() {
    return heap[1];
}

int main() {
    insert(10);
    insert(45);
    insert(19);
    insert(11);
    insert(96);
    
    int n = sz;
    for (int i=1; i<=n; i++) {
		printf("delete : [%d]\n", delete());
	}
}