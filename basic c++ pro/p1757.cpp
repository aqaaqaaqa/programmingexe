//
// Created by 10154 on 2023/6/30.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "cstring"

using namespace std;

const int N = 3000;

int dp[N][N];
int m, n;
int zu[N], w[110][N], v[110][N];


int main(){
    cin >> m >> n;

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        zu[c]++;
        w[c][zu[c]] = b;
        v[c][zu[c]] = a;
    }
    int zushu = 0;

    for(int i = 1; i <= N; i++){
        if(zu[i] != 0) zushu ++;
    }

    for(int i = 1; i <= zushu; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            for(int k = 1; k <= zu[i]; k++){
                if(j - v[i][k] >= 0)dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }

    cout << dp[zushu][m];
}
