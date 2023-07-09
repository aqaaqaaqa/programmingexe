//
// Created by 10154 on 2023/7/9.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N = 5e4 + 10;
struct Niu{
    int w, s, num;
    bool operator < (Niu W){
        return (w + s) < W.w + W.s;
    }
} niu[N];

int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> niu[i].w >> niu[i].s;
        niu[i].num = i + 1;
    }

    sort(niu, niu + n);

    int res = -2e8;
    int ww = 0;

    for(int i = 0; i < n; i++){
        int aa = ww - niu[i].s;
        if(res < aa) res = aa;
        ww += niu[i].w;
    }

    cout << res;
}

