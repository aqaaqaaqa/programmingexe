//
// Created by 10154 on 2023/4/21.
//

#include "iostream"
#include "algorithm"


using namespace std;

int quick_chooose(int l ,int r ,int q[], int k){
    if(l >= r)
        return q[l];

    int i = l - 1, j = r + 1, x = q[l];

    while (i < j){
        do i ++;while (q[i] < x);
        do j --;while (q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;

    if(sl >= k)
        return quick_chooose(l , j, q, k);
    if(sl < k)
        return quick_chooose(j + 1, r, q, k - sl);
}


int main(){
    int n, k;
    int q[10010];
    scanf("%d%d", &n, &k);
    for( int i = 0; i < n ; i++ ){
        scanf("%d", &q[i]);
    }
    sort(q, q + n);
    int x = unique(q, q + n) - q;
    if(x < k)
    {
        cout << "NO RESULT"<< endl;
        return 0;
    }
    cout << quick_chooose(0, x - 1, q, k)<< endl;
}