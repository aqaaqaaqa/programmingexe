//
// Created by 10154 on 2022/5/30.
//

#include "iostream"
#include "vector"

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size())
        return add(B, A);

    vector<int> C;
    int k = 0;
    for(int i = 0 ; i < A.size() ; i++){
        k += A[i];
        if(i < B.size()) k += B[i];
        C.push_back(k % 10);
        k /= 10;
    }
    if(k == 1) C.push_back(k);
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(int i = a.size() - 1 ; i >= 0 ; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = b.size() - 1 ; i >= 0 ; i--){
        B.push_back(b[i] - '0');
    }
    vector<int> c = add(A, B);
    for(int i = c.size() - 1 ; i >= 0 ; i--){
        cout << c[i];
    }
}