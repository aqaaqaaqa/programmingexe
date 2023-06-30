//
// Created by 10154 on 2023/6/30.
//

#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"


using namespace std;

const int N = 3000;

int fama[6] = {1, 2, 3, 5, 10, 20};
int v[N], w[N], s[6];
int dp[N][N];


int main(){
    int n;
    int cnt = 0;
    for(int i = 0; i < 6;i ++){
        cin >> s[i];
    }

    for(int i = 0; i < 6; i++){
        int a, b;
        a = fama[i];
        int k = 1;
        while(k <= s[i]){
            cnt++;
            v[cnt] = k * a;
            s[i] -= k;
            k *= 2;
        }
        if(s[i] > 0){
            cnt++;
            v[cnt] = s[i] * a;
        }
    }
    n = cnt;

    for(int i = 0; i < N; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1000; j++){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] += dp[i - 1][j - v[i]];
        }

    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        if(dp[n][i] !=0)
            ans++;
    }
    cout << "Total=" << ans;
}