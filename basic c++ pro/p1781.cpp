//
// Created by 10154 on 2023/4/14.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size()> B.size();
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}


int main(){
    vector<int> A[21];
    string a[21];
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++ ){
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++ ){
        for(long long j = a[i].size() - 1; j >=0 ; j --){
            A[i].push_back(a[i][j] - '0');
        }
    }
    int max = 0;
    for(int i = 0 ; i < n - 1; i++ ){
        if(!cmp(A[max], A[i + 1]))
            max = i + 1;
    }
    cout << max + 1 << endl;

    for(int i = A[max].size() - 1; i >= 0; i--){
        cout<< A[max][i];
    }
}