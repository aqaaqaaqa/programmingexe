//
// Created by 10154 on 2022/6/5.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> div(vector<int> &A, long long B, int &c){
    long long k = 0;
    vector<int> C;

    for(long long i = A.size() - 1; i >= 0; i -- ){
        k = k * 10 + A[i];
        C.push_back(k / B);
        k %= B;
    }
    reverse(C.begin() , C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main(){
    vector<int> A;
    string a;
    long long B;
    cin >> a >> B;

    int yu;

    for(long long i = a.size() - 1; i >= 0; i -- ){
        A.push_back(a[i] - '0');
    }

    auto c = div(A, B, yu);
    reverse(c.begin(), c.end());
    for(int i = 0 ; i< c.size(); i++){
        cout << c[i];
    }
}