//
// Created by 10154 on 2023/5/3.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    long long  num[200000];
    for(int i = 0 ; i < n ; i++) scanf("%d", &num[i]);
    sort(num, num + n);
    int sum = 0;
    for(int i = 0, r1 = 0 , r2 = 0 ; i < n; i++){
        while(num[r1] - num[i] <= c && r1 < n) r1++;
        while(num[r2] - num[i] < c && r2 < n) r2++;
        if(num[r2] - num[i] == c && num[r1 - 1] - num[i] == c  && r1 - 1 >= 1) sum +=r1 -r2;
    }
    cout << sum;
}