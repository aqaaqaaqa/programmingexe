//
// Created by 10154 on 2023/6/17.
//

#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

const int N = 2e5 + 10;

int h[N], e[N], ne[N], idx;
int n, m;
int color[N];
bool flag;
int res1, res2, ans;


void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int a, int s){
    if(s == 1) res1++;
    else if(s == 2) res2++;
    color[a] = s;

    for(int i = h[a]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3 - s)){
                return false;
            }
        }
        else if(color[j] == s) {
            return false;
        }
    }
    return true;

}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        insert(a, b);
        insert(b, a);
    }
    flag = true;

    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
            ans +=min(res2, res1);
            res1 = res2 = 0;
        }
    }
    if(!flag) cout << "Impossible";
    else cout << ans;
}