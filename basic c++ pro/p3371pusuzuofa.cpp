//
// Created by 10154 on 2023/6/8.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string.h"
#include "math.h"

using namespace std;

const int N = 1010;

int g[N][N];
int dist[N];
bool st[N];
int n, m, s;
int u, v, w;



int dijkstra(int t){
    memset(dist, 0x3f, sizeof dist);

    dist[t] = 0;
    for(int i = 0; i < n - 1; i++){
        int t = -1;
        for(int j = 1; j <= n ; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] != 0x3f3f3f3f) {
            printf("%d ", dist[i]);
        }
        else{
            printf("%d ", pow(2, 31) - 1);
        }
    }

}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i< m; i++){
        scanf("%d%d%d", &u,&v,&w);
        g[u][v] = min(g[u][v], w);
    }
    dijkstra(s);
}