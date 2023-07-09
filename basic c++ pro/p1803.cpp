//
// Created by 10154 on 2023/7/8.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 1e6 + 10;
int n;
struct Range{
    int l, r;

    bool operator < (Range & W){
        return r < W.r;
    }
}range[N];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> range[i].l >> range[i].r;
    }

    sort(range, range + n);

    int res = 0;
    int rpoint = -2e9;

    for(int i = 0; i < n; i++){
        if(rpoint <= range[i].l){
            res++;
            rpoint = range[i].r;
        }
    }

    cout << res;
}