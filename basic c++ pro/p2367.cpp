//
// Created by 10154 on 2022/6/10.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 5000010;
int n, p;
int q[N] = {0}, b[N] = {0};

void insert(int l , int r , int num){
    b[l] +=num;
    b[r + 1] -= num;
}

int main(){
    cin >> n >> p;
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d",&q[i]);
    }

    for(int i = 1 ; i <= n ; i ++){
        insert(i , i , q[i]);
    }

    int x,y,z;
    while(p--){
        scanf("%d%d%d",&x, &y, &z);
        insert(x, y, z);
    }
    int min = b[1];
    for(int i = 1 ; i <= n ; i ++){
        b[i] += b[i - 1];
        if(b[i] < min)
            min = b[i];
    }
    cout << min;
}