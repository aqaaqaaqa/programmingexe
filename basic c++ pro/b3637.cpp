//
// Created by 10154 on 2023/7/2.
//
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"

using namespace std;

const int N = 5010;

int dp[N];
int n;
int a[N];



int main(){
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }


    int max1 = 0;

    for(int i = 1; i <= n; i++){
        max1 = max(max1, dp[i]);
    }

    cout << max1;
}