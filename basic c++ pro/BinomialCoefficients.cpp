//
// Created by 10154 on 2022/9/22.
//

#include<iostream>
#include <vector>
using namespace std;
const int c = 1e9+7;
unsigned long long A[2010][2010];
unsigned long long zuheshu(int a,int b){
    for (int i = 0; i <= a; i ++){
        A[i][0] = 1;
        A[i][i] = 1;
    }
    for(int i = 1; i <= a; i ++){
        for(int j = 1; j <= b; j ++){
            A[i][j] = (A[i - 1][j - 1] + A[i - 1][j]) % c;
        }
    }
    return A[a][b];
}
int main(){
    int a,b;
    long long ans;
    cin >> a >> b;
    //ans = zuheshu(a ,b) % c;
    cout << zuheshu(a ,b);
}