//
// Created by 10154 on 2023/5/16.
//

#include "iostream"
#include "cstdio"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 3e6 + 10;


vector<int> stk; int point = 0, point2 = 0;
int stk2[1000010];int stk4[1000010];
vector<int> stk3;


int find(int x, int j){
    for(int i = j; i >= 0; i--){
        if(x == stk[i])
            return i;
    }
}

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        stk.push_back(a);
    }
    reverse(stk.begin(), stk.end());
    for(int i = 0; i < n ; i++){
        while (point && stk2[point] <= stk[i]) {point--; point2--;}
        if(point) stk3.push_back(stk4[point2]);
        else stk3.push_back(0);
        stk2[++ point] = stk[i];
        stk4[++ point2] = stk.size() - i;
    }
    reverse(stk3.begin(), stk3.end());
    for(int i = 0; i < stk3.size(); i++){
        cout << stk3[i] << ' ';
    }
}