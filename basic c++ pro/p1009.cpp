//
// Created by 10154 on 2023/4/24.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size())
        return add(B, A);

    vector<int> C;
    int t = 0;

    for (int i = 0 ; i < A.size(); i++){
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for (int i = 0 ; i < A.size()|| t != 0; i++){
        if(i < A.size()) t = A[i] * b + t;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

vector<int> fact(int n){
    vector <int>c;
    c.push_back(2);
    for(int i = 3; i <= n; i++){
        c = mul(c, i);
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    vector<int> c;
    c.push_back(3);
    for(int i = 3; i <= n; i ++){
        vector<int> a1 = fact(i);
        c = add(a1, c);
    }

    for(int i = c.size() - 1; i >= 0; i--){
        cout << c[i];
    }
}