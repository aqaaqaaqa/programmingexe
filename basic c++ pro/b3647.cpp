//
// Created by 10154 on 2023/6/15.
//

#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

const int N = 110;

int d[N][N];


int main(){
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
        }
    }
    while (m--){
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

}