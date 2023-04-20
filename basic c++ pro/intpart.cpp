//
// Created by 10154 on 2022/11/1.
//
#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
int result[2010][2010];
int n, k;

void init(){
    for(int i = 1; i < 2010; i++){
        result[1][i] = 1;
        result[i][1] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= k; j++){
            if(j > i)
                result[i][j] = result[i][i];
            else if(j == i)
                result[i][j] = (result[i][i - 1] + 1) % mod;
            else
                result[i][j] = (result[i][j - 1] + result[i - j][j]) % mod;
        }
    }
}



int split(int n,int k)
{
    if(n == 1 || k == 1)
        return 1;
    else if(n < k)
        return split(n, n);
    else if(n == k)
        return (split(n, n-1) + 1) % mod;
    else
        return (split(n, k-1) + split(n-k, k)) % mod;
}

int main()
{
    cin >> n >> k;
    init();
    cout << result[n][k] <<endl;
    //cout << split(n, k);
    return 0;
}
