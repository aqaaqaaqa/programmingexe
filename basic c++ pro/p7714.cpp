//
// Created by 10154 on 2022/6/12.
//

#include "iostream"

using namespace std;

const int N = 1000010;
int a[N], b[N];

void insert(int l , int r , int num){
    b[l] += num;
    b[r + 1] -= num;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        int n, ans = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i ++ ) scanf("%d", &a[i]);
        for(int i = 1 ; i <= n ; i ++ ) insert(i , i , a[i]);
        for(int i = 1 , j = 1; i <= n ; i ++ ){

        }
    }
}