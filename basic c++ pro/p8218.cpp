//
// Created by 10154 on 2023/4/27.
//
#include "iostream"
 using namespace std;

const int N = 1e5;

int sum[N] = {0};
int a[N];
void qianzhuihe(int n){
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
}
int main(){
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    qianzhuihe(n);
    cin >> m;
    int l, r;
    for(int i = 0; i  < m; i++){
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

}