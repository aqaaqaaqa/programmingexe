//
// Created by 10154 on 2023/7/4.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 6e4 + 10;
int h[10 * N], e[10 * N], ne[10 * N], idx;
int dp[N][2];
int happy[N];
int n;
bool root[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x){
    dp[x][1] = happy[x];

    for(int i = h[x]; i != -1; i = ne[i]){
        int a = e[i];
        dfs(a);
        dp[x][1] += dp[a][0];
        dp[x][0] += max(dp[a][1], dp[a][0]);
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> happy[i];
    }
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
        root[a] = true;
    }

    int roottrue;
    for(int i = 1; i <= n; i++){
        if(!root[i]) roottrue = i;
    }

    dfs(roottrue);

    cout << max(dp[roottrue][0], dp[roottrue][1]);
}