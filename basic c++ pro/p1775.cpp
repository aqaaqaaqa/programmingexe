//
// Created by 10154 on 2023/7/2.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 310;

int n;
int m[N];
int dp[N][N];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> m[i];
    }

    for(int i = 1; i <= n; i++){
        m[i] += m[i - 1];
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int l = i;
            int r = i + len - 1;
            dp[l][r] = 1e8;
            for(int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + m[r] - m[l - 1]);
        }
    }

    cout  << dp[1][n];
}


