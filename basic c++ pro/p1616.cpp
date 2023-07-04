//
// Created by 10154 on 2023/6/20.
//

#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

const int N = 1010;

int t, m;
int v[N * 10], w[N * 10];
long long f[10000010];


int main(){
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> v[i] >> w[i];
    }
    long long res = 0;

    for(register int i=1;i<=m;++i){
        for(register int j=v[i];j<=t;++j){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
            res=max(res,f[j]);//所有的可能当中取最大值
        }
    }
    cout << res;
}