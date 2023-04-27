//
// Created by 10154 on 2023/4/24.
//

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

vector<int> factorial(vector<int> &A, int n){
    vector<int> C;
    int t = 0;
        for(int j = 0; j < A.size() || t != 0; j ++){
            if(j < A.size()) t = n * A[j] + t;
            C.push_back(t % 10);
            t /= 10;
        }
    return C;
}

void find(int n, int a){
    vector <int>c;
    c.push_back(2);
    for(int i = 3; i <= n; i++){
        c = factorial(c, i);
    }
    int times = 0;
    for(int i = 0; i < c.size(); i++){
        if(c[i] == a) times++;
    }
    cout << times<< endl;
}


int main(){
    int t;
    int n[11], a[11];
    cin >> t;
    for(int i = 0; i < t; i ++){
        cin >> n[i] >> a[i];
    }
    for(int i = 0; i < t; i ++){
        find(n[i], a[i]);
    }
}