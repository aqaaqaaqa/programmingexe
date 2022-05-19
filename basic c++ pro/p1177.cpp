//
// Created by 10154 on 2022/5/7.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N=1e5 + 10;
int q[N];
int n;

int choose_best(int l ,int m ,int r){
    int x1 = max(l, m);  // 把 a，b 中大的值赋给 x1
    int x2 = max(x1, r);  // 把 x1，c 中大的值赋给 x2

    return x2;
}

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
//    int x=q[(l + r) >> 1], i = l - 1, j = r + 1;

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j){
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    quick_sort(q, l ,j);
    quick_sort(q, j + 1 ,r);
}

int main(){
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &q[i]);
    }
    quick_sort(q ,0 , n-1);
    for(int i = 0 ; i < n ; i++){
        printf("%d",q[i]);
    }
}

