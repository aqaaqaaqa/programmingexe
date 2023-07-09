//
// Created by 10154 on 2023/7/9.
//
#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
#include "iomanip"
using namespace std;

const int N = 1010;
typedef pair<int , int> pii;

int n;
pii t[N];


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i].first;
        t[i].second = i + 1;
    }

    sort(t, t + n);
    double ans = 0;

    for(int i = 0; i < n; i++){
        cout << t[i].second << ' ';
        ans += t[i].first * (n - i - 1);
    }
    cout << '\n';

    cout << fixed << setprecision(2) << ans/n;

}