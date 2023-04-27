//
// Created by 10154 on 2023/4/24.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size())
        return add(B, A);
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size(); i++){
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    auto c = add(A, B);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i];

}


