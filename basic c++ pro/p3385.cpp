#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

const int N = 4e4 + 10;

int n, m;
bool falg1 = false;
int idx = 0;
struct edge{
    int a, b, w1;
}edges[2 * N];

int dist[N], back[N];


void bellman(){
    memset(dist, 0x3f, sizeof dist);
    bool flag = false;
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        memcpy(back, dist, sizeof dist);
        for(int j = 0; j < idx; j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w1;
            if(dist[b] > dist[a] + w && i == n - 1){
                flag = true;
            }
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    if(flag && falg1) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int u, v, w;
        cin >> n >> m;
        idx = 0;
        while(m --){
            cin >> u >> v >> w;
            if(u == 1 || (w >= 0 && v == 1))
                falg1 = true;
            if(w >= 0){
                edges[idx].a = u;
                edges[idx].b = v;
                edges[idx++].w1 = w;
                edges[idx].a = v;
                edges[idx].b = u;
                edges[idx++].w1 = w;
            }
            else{
                edges[idx].a = u;
                edges[idx].b = v;
                edges[idx++].w1 = w;
            }
        }
        bellman();
    }
}




