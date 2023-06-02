//
// Created by 10154 on 2023/6/2.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string.h"

using namespace std;
const int N = 1e5 + 10;
const int M = 1e7 + 10;

int h[N], e[M], ne[M], idx;
int m, n;
bool st[N];
int que[N];

void sortinsert(int a, int b){
    int nex;
    if(h[a] == -1){
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }
    else {
        for (int i = h[a]; i != -1; i = ne[i]) {
            nex = ne[i];
            if(nex == -1 && e[i] > b){
                e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ; break;
            }
            if(nex == -1 && e[i] < b){
                e[idx] = b;
                ne[idx] = nex;
                ne[i] = idx++;
                break;
            }
            if (e[i] < b && e[nex] > b) {
                e[idx] = b;
                ne[idx] = nex;
                ne[i] = idx++;
                break;
            }
        }
    }
}

void dfs(int u){
    st[u] = true;
    cout << u << ' ';
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) dfs(j);
    }
}

void bfs(){
    int hh = 0, tt = 0;
    que[0] = 1;
    st[1] = true;
    while(hh <= tt){
        auto t = que[hh ++];
        cout << t <<' ';
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(!st[j]){
                que[++tt] = j;
                st[j] = true;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(st, false, sizeof st);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        sortinsert(x, y);
    }
    dfs(1);
    cout << '\n';
    memset(st, false, sizeof st);
    bfs();
}