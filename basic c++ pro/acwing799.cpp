//
// Created by 10154 on 2023/4/29.
//

#include "iostream"
#include "math.h"
using namespace std;

const int N = 1e6;
int sum[N], a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = 0;
    for(int i = 0, j = 0 ; j < n; j++){
        sum[a[j]]++;
        while(i <= j && sum[a[j]] != 1) { sum[a[i]]--; i++;}
        m = max(m, j - i + 1);
    }
    cout << m;
}

