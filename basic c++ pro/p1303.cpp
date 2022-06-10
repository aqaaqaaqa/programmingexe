//
// Created by 10154 on 2022/6/1.
//
#include "iostream"
#include "vector"

using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B){
    vector<int> C(4010);
    for(int j = 0 ; j < B.size() ; j ++) {
        int k = 0;
        for (int i = 0; i < A.size() || k > 0; i++) {
            if (i < A.size())k = k + A[i] * B[j] + C[i + j];
            C[i + j] = k % 10;
            k = k / 10;
        }
    }
    while(C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(long long  i = a.size() - 1;i >= 0; i--) A.push_back(a[i] - '0');
    for(long long  i = b.size() - 1;i >= 0; i--) B.push_back(b[i] - '0');
    auto c = mul(A, B);
    for(long long i = c.size() - 1 ; i >= 0 ; i--){
        cout << c[i];
    }
}