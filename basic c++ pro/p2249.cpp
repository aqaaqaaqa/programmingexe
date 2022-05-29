//
// Created by 10154 on 2022/5/27.
//

#include "iostream"

using namespace std;

const int N = 1000000, M = 100000;
int n, m;
int q[N], p[M];

int Bsearch(int l ,int r, int num){
    while(l < r) {
        int mid = (l + r) >> 1;
        if (q[mid] >= num){
            r = mid;
        }
        else l = mid + 1;
    }
    return l;
}

int main (void){
    for(int i = 0; i < M; i++){
        p[i] = -2;
    }
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%d", &q[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &p[i]);
    }
    int i = 0;
    while (p[i] != -2){
        int a = Bsearch(0, n - 1, p[i]);
        if(q[a] != p[i])
            a = -2;
        p[i] = a + 1;
        i++;
    }
    i = 0;
    while (p[i] != -2){
        printf("%d ",p[i]);
        i++;
    }
}