//
// Created by 10154 on 2023/6/19.
//

#include "iostream"
#include "string.h"
#include "algorithm"

using namespace std;

const int N = 5e4 + 10;

int n, m, e1;
int h[N], e[N], ne[N], idx;
int match[N];
int st[N];

void insert(int a, int b ){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> e1;
    int u, v;
    memset(h, -1, sizeof h);
    while (e1--){
        cin >> u >> v;
        insert(u, v);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    cout << res;
}