//
// Created by 10154 on 2023/4/26.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
//int N = 1e9;
using namespace std;

bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() > B.size();
    for(long long i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> mul (vector<int> &A, vector<int> &B){
    if(A.size() < B.size())
        return mul(B, A);
    vector<int> C;
    int wei = -1;
    for(int i = 0; i < A.size(); i++){
        int t = 0;
        for(int j = 0; j < B.size() || t; j++){
            if(wei + 1 == j +i) {C.push_back(0); wei++;}
            if(j < B.size()) t = A[i] * B[j] + t + C[i + j];
            C[i + j] = t % 10;
            t /= 10;
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t += A[i];
        if(B.size() > i) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

vector<int> sub(vector<int> &A, vector<int> &B){
    if(!cmp(A, B)) {cout << '-';return sub(B ,A);}
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t = A[i] - t;
        if(B.size() > i) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t >= 0) t = 0;
        else t = 1;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
vector<int> slidewin(vector<int> A, long long num){
    vector<int> B;
    for(int i = 0; i < num; i++){
        B.push_back(A[A.size() - 1 - i]);
    }
    return B;
}

vector<int> slidewin1(vector<int> A, vector<int> yushu, long long num){
    if(A.size() - num >= 0)
        yushu.push_back(A[A.size() - num]);
    return yushu;
}

vector<int> div(vector<int> &A, vector<int> &B, vector<int> &yushu){
    vector<int> C;
    if(cmp(B,A)){
        yushu = A;
        C.push_back(0);
        return C;
    }
    yushu = slidewin(A, B.size());
    reverse(yushu.begin(), yushu.end());
    for(long long i = 0, j = -1; i < A.size() - B.size() + 1; i++) {
        //if(cmp(yushu, B)){
            C.push_back(0);
            j++;
        //}
        //if(cmp(yushu, B))
        while (cmp(yushu, B)) {
            yushu = sub(yushu, B);
            C[j]++;
        }
        reverse(yushu.begin(), yushu.end());
        yushu = slidewin1(A, yushu, B.size() + i + 1);
        if(B.size() + i + 1 == A.size() + 1)
            yushu.pop_back();
        reverse(yushu.begin(), yushu.end());
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a, b;
    vector<int> A, B, yushu;
    vector<int> c;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');


    c = add(A, B);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i] ;
    cout << endl;
    c = sub(A, B);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i] ;
    cout << endl;
    c = mul(A, B);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i] ;
    cout << endl;
    c = div(A, B, yushu);
    for(int i = c.size() - 1; i >= 0; i--) cout << c[i] ;
    cout << endl;
    for(int i = yushu.size() - 1; i >= 0; i--) cout << yushu[i];

}