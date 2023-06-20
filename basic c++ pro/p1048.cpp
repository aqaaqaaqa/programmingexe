//
// Created by 10154 on 2023/6/20.
//

#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

const int N = 1010;

int t, m;
int v[N], w[N];
int f[N][N];


int main(){
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> v[i] >> w[i];
    }

    for(int i = 1; i <= m; i++)
        for(int j = 0 ; j <= t; j++){
            f[i][j] = f[i - 1][j];
            if(v[i] <= j) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[m][t];
}






