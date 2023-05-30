//
// Created by 10154 on 2023/5/30.
//

#include "iostream"
#include "algorithm"
#include "string"
#include "vector"

using namespace std;

int n, num = 0;
bool lie[15] , duijiaoxian[30], fanduijiaoxian[30] ;
vector<int> liehao;

void dfs(int l ){
    if(l == n ){
        if(num  < 3) {
            for (int i = 0; i < n; i++) {
                cout << liehao[i] + 1<< ' ';
            }
            cout << '\n';
        }
        num ++ ;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!lie[i] && !duijiaoxian[i + l] && !fanduijiaoxian[l - i + n]){
            liehao.push_back(i);
            lie[i] = true;
            duijiaoxian[i + l] = true;
            fanduijiaoxian[l - i + n] = true;
            dfs(l + 1);
            lie[i] = false;
            duijiaoxian[i + l] = false;
            fanduijiaoxian[l - i + n] = false;
            liehao.pop_back();
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;

    dfs(0);

    cout << num << '\n';

}


