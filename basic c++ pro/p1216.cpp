//
// Created by 10154 on 2023/7/2.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "cstring"

using namespace std;

const int N = 2000;

int dp[N][N];
int r;
int sanjiao[N][N];

int main(){
    cin >> r;
    for(int i = 1; i <=r ;i ++){
        for(int j = 1; j <= i; j++){
            cin >> sanjiao[i][j];
        }
    }

    for(int i = 1; i<= r ; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i -1][j]) + sanjiao[i][j];
        }
    }
    int max1 = 0;
    for(int i = 1; i < N; i++) {
        max1 = max(max1, dp[r][i]);
    }
    cout << max1;
}