//
// Created by 10154 on 2022/5/29.
//

#include "iostream"
#include "algorithm"

using namespace std;

int q[110];

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = q[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j){
        do i++; while (q[i] < mid);
        do j--; while (q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &q[i]);
    }

    quick_sort(q, 0, n-1);

    int i,j;
    for(i = 0, j = 1;j < n; j++){
        if(q[i] != q[j])
            q[++i] = q[j];
    }

    cout << i + 1 << endl;
    for(int j = 0; j < i + 1; j++){
        printf("%d ",q[j]);
    }
}