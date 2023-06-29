//
// Created by 10154 on 2023/6/29.
//

#include "iostream"
#include "algorithm"
#include "string.h"
#include "vector"

using namespace std;

const int N = 1e6 + 10;


int sushu[4] = {0, 1, 5, 11};
int n;
long long dp[5][N];

int main(){
    cin >> n;

    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i < 5 ;i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i < 4; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - sushu[i] >= 0)dp[i][j] = min(dp[i][j], dp[i][j - sushu[i]] + 1);
        }
    }

    cout << dp[3][n];
}

