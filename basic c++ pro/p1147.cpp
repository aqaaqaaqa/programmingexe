//
// Created by 10154 on 2023/5/3.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;



int main(){
    int m;
    vector<int> num;
    int sum = 0;
    cin >> m;
    int l[1000], r[1000];
    int n = 0;
    for(int i = 0; i < m; i++) num.push_back(i + 1);
    for(int i = 0, j = 0; j < m; j ++){
        sum += num[j];
        if(sum == m && j != m - 1) { l[n] = i + 1; r[n] = j + 1; n++;}
        while(i < j && sum > m) {sum -= num[i];   i++;}
        if(sum == m && j != m - 1) { l[n] = i + 1; r[n] = j + 1; n++;}
    }
    for(int i = 0; i < n; i++) {cout << l[i] << ' ' << r[i]; if(i != n - 1) cout << endl;}
}