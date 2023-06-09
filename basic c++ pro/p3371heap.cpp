//
// Created by 10154 on 2023/6/7.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string.h"
#include "math.h"
#include "queue"

using namespace std;

const int N = 2e6 + 2;

typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m, s;
int u, v, w1;

void insert(int u, int v, int w1){
    e[idx] = v;
    w[idx] = w1;
    ne[idx] = h[u];
    h[u] = idx++;
}

int dijkstra(int t){
    memset(dist, 0x3f, sizeof dist);
    dist[t] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, t});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        int dis = t.first;
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dis + w[i]){
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    for(int i =  1; i <= n; i++){
        if(dist[i] != 0x3f3f3f3f) {
            printf("%d ", dist[i]);
        }
        else{
            printf("%d ", 0x7fffffff);
        }
    }

}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    memset(h, -1, sizeof h);
    for(int i = 0; i< m; i++){
        scanf("%d%d%d", &u,&v,&w1);
        insert(u, v, w1);
    }
    dijkstra(s);
}