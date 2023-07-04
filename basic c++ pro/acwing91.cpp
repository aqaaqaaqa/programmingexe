//
// Created by 10154 on 2023/7/4.
//

#include "iostream"
#include "algorithm"
#include "cstring"
#include "string.h"

using namespace std;

const int N = 21, M = 1 << N;

int dp[N][M];
int tu[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tu[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0;
    for(int j = 0; j < 1 << n; j++){
    for(int i = 0; i < n; i++){
//遍历的顺序很重要，当i在前时，dp[i]的所有情况可能并不会都更新到。可能变大的那一维度，要后遍历。
            if(j >> i & 1)
            for(int k = 0; k < n; k++) {
                if(j - ( 1 << i ) >> k & 1)
                dp[i][j] = min(dp[i][j], dp[k][j - (1 << i)] + tu[k][i]);
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1];
}


