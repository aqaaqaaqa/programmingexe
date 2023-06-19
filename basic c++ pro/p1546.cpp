//
// Created by 10154 on 2023/6/15.
//
#include "iostream"
#include "algorithm"
#include "string.h"
#include "vector"

using namespace std;

const int N = 400;
int idx = 1;
int p[N];
int n;

struct Edge {
    int a, b, w;

    bool operator < (const Edge &W)const{
        return w < W.w;
    }
} edges[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int kriskal(){
    sort(edges, edges + idx);
    for(int i = 1; i <= n; i++) p[i] = i;
    int res = 0, cnt = 0;
    for(int i = 0; i < idx; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);

        if(a != b){
            p[a] = b;
            cnt ++;
            res += w;
        }
    }
    if(cnt < n - 1) return 0x3f3f3f3f;
    else return res;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edges[idx].w;
            edges[idx].a = i;
            edges[idx++].b = j;
        }
    }

    int temp = kriskal();
    cout << temp;
}


int n, m;
int p[N];

struct Edge{
    int a, b, w;

    bool operator < (const Edge &W) const{
        return w < W.w;
    }
} edges[M];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edges, edges + m);

    for(int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt =
}