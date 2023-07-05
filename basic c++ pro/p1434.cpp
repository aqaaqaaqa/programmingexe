//
// Created by 10154 on 2023/7/5.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 110;
int dp[N][N];
int tu[N][N];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


int dfs(int x, int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 1 && b >= 1 && a <= n && b <= m && tu[a][b] < tu[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(a, b) + 1);
        }
    }
    return dp[x][y];
}



int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m;j ++){
            cin >> tu[i][j];
        }

    int res = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m;j ++){
            res = max(res, dfs(i, j));
        }

    cout << res;

}
