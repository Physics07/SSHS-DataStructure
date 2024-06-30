#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
#define M 1000

int weight[MAX_VERTICES][MAX_VERTICES] = {
    {0, 3, 17, 6, M, M, M},
    {3, 0, M, 5, M, M, 12},
    {17, M, 0, M, 10, 8, M},
    {6, 5, M, 0, 9, M, M},
    {M, M, 10, 9, 0, 4, 2},
    {M, M, 8, M, 4, 0, 14},
    {M, 12, M, M, 2, 14, 0}
};

int dist[MAX_VERTICES];
int visited[MAX_VERTICES];

int prim(int s, int n) {
    for(int i=0; i<n; i++) dist[i] = weight[s][i];
    visited[s] = 1;
    int ans = 0;
    for(int i=1; i<n; i++) {
        int arg = 0, k = M;
        for(int j=0; j<n; j++) if(!visited[j] && dist[j]) {
            if(k > dist[j]) {
                k = dist[j];
                arg = j;
            }
        }
        ans += k;
        for(int j=0; j<n; j++) if(dist[j] > weight[arg][j]) {
            dist[j] = weight[arg][j];
        }
    }
    return ans;
}

int main() {
    printf("%d", prim(0, MAX_VERTICES));
}