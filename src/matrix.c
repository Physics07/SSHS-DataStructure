#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int x, y, v;
} term;

void smTranspose(term a[], term b[]) {
    int n = a[0].v, m = a[0].y;
    b[0] = (term) {a[0].y, a[0].x, a[0].v};

    int rowTerms[100] = { 0 };
    int startingPos[100] = { 0 };
    for(int i=1; i<=n; i++) rowTerms[a[i].y]++;
    startingPos[0] = 1;
    for(int i=1; i<m; i++) startingPos[i] = startingPos[i-1] + rowTerms[i-1];

    for(int i=1; i<=n; i++) {
        b[startingPos[a[i].y]] = (term) {a[i].y, a[i].x, a[i].v};
        startingPos[a[i].y]++;
    }
}

int main() {
    // a[0].x stores the number of rows
    // a[0].y stores the number of columns
    // a[0].v stores the number of values
    term a[11] = {
        { 8, 7, 10 },
        { 0, 2, 2 },
        { 0, 6, 12 },
        { 1, 4, 7 },
        { 2, 0, 23 },
        { 3, 3, 31 },
        { 4, 1, 14 },
        { 4, 5, 25 },
        { 5, 6, 6 },
        { 6, 0, 52 },
        { 7, 4, 11 }
    };
    term b[11] = { { 0, 0, 0 } };
    
    smTranspose(a, b);

    for(int i=0; i<=b[0].v; i++) printf("%d %d %d\n", b[i].x, b[i].y, b[i].v);
}