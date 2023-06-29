//
// Created by 10154 on 2023/6/28.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string.h"

using namespace std;

const int N = 3e4 + 10;

int n, m;
long long v[N], p[N];
long long f[50][N];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> v[i] >> p[i];
    }

    for(int i = 1; i <= m; i++)
        for(int j = 0; j <= n; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i] * p[i]);
        }

    cout << f[m][n];
}