//
// Created by 10154 on 2023/7/4.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 12, M = 1 << N;
long long dp[N][M];
bool st[M];
int n, m;

int main(){
    while(cin >> n >> m, m || n){
        memset(dp, 0, sizeof dp);//多次使用dp所以要初始化
        for(int i = 0; i < 1 << n; i++){
            st[i] = true;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;// 偶数在二进制中最后一位一定是0，所以和1与结果一定是0
                    cnt = 0;
                }
                else cnt ++;
            }
            if(cnt & 1) st[i] = false;
        }

        dp[0][0] = 1;

        for(int i = 1; i <= m; i++)
            for(int j = 0; j < 1 << n; j++)
                for(int k = 0; k < 1 << n; k++){
                    if((j & k) == 0 && st[j | k] )
                        dp[i][j] += dp[i - 1][k];
                }
        cout << dp[m][0]<< endl;
    }
}