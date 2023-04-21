//
// Created by 10154 on 2023/4/21.
//

#include "iostream"
#include "algorithm"
#include <stdlib.h>

using namespace std;

bool check1(int p, int k){
    if(p <= k) return true;
    else return false;
}
bool check2(int p, int k){
    if(p <= k) return false;
    else return true;
}

int main(){
    int m, n;
    int q[100010], p[100010];
    scanf("%d%d", &m, &n);
    for( int i = 0; i < m ; i++){
        scanf("%d", &q[i]);
    }
    for( int i = 0; i < n ; i++){
        scanf("%d", &p[i]);
    }

    sort(q, q + m);
    int sum [100010] = {0};

    for(int i = 0; i < n; i ++){
        int l = 0, r = m - 1;
        while(l < r){
            int mid = (l + r + 1)>> 1;
            if(check1(q[mid], p[i])){
                l = mid;
            }
            else r = mid - 1;
        }
        sum[i] = abs(p[i] - q[l]);
    }

    for(int i = 0; i < n; i++){
        int l = 0, r = m - 1;
        while(l < r){
            int mid = (l + r)>> 1;
            if(check2(q[mid], p[i])){
                r = mid;
            }
            else l = mid + 1;
        }
        if(sum[i] > abs(p[i] - q[l]))
            sum[i] = abs(p[i] - q[l]);
    }

    long long sumtotal = 0;
    for( int i = 0; i < n; i ++)
        sumtotal += sum[i];


    cout << sumtotal << endl;

}