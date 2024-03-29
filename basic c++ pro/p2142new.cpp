//
// Created by 10154 on 2023/4/24.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() > B.size();

    for(int i = A.size() - 1 ; i >= 0; i--){
        if(A[i] > B[i]) return true;
        else if(A[i] < B[i]) return false;
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B){

    vector<int> C;
    int t = 0;
    for(int i = 0 ; i < A.size(); i ++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10 )% 10);
        if(t >= 0) t = 0;
        else t = 1;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a, b;
    vector<int> A, B, c;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    if(cmp(A, B)) c = sub(A, B);
    else {
        c = sub(B, A);
        cout << '-';
    }
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i];
}