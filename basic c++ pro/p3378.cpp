//
// Created by 10154 on 2023/5/22.
//
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

const int N = 1e6 + 10;

int h[N], size;

void down(int a){
    int t = a;
    if( a * 2 <= size && h[t] > h[ a * 2]) t = a * 2;
    if( a * 2 + 1 <= size && h[t] > h[ a * 2 + 1]) t = a * 2 + 1;
    if(t != a){
        swap(h[a], h[t]);
        down(t);
    }
}

void up(int a){
    while(a / 2 && h[a / 2] > h[a]){
        swap(h[a / 2], h[a]);
        a /= 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int op, x;

    cin >> n;
    while (n --){
        cin >> op;
        if(op == 1){
            cin >> x;
            h[++ size] = x;
            up(size);
            down(size);
        }
        if(op == 2){
            cout << h[1] << endl;
        }
        if(op == 3){
            swap(h[1], h[size]);
            size --;
            up(1);
            down(1);

        }
    }
}
