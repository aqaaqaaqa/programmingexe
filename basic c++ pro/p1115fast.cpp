//
// Created by 10154 on 2022/6/8.
//
#include "iostream"

using namespace std;

int a[200010];

int main(){
    int n;
    cin >> n;
    int s = 0, max = -100000;
    for(int i = 1 ; i<= n ; i ++){
        scanf("%d", &a[i]);
        s += a[i];
        if(s > max) max = s;
        if(s < 0) s = 0;
    }
    cout << max;
}