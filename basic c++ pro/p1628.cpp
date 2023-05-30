//
// Created by 10154 on 2023/5/22.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

const int N = 1e5 + 10;
string str;

int son[N][26], cnt[N], idx;
vector<char> str1;

void insert(string x){
    int p = 0;
    for(int i = 0; x[i]; i ++){
        int a = x[i] - 'a';
        if (!son[p][a]) son[p][a] = ++ idx;//idx是看看它下一个字母应该存到第几层去。
        p = son[p][a];
    }
    cnt[p] ++;

}

int query(string x){
    int p = 0;
    for(int i = 0; i < x.size(); i ++){
        int a = x[i] - 'a';
        if(son[p][a] != 0) p = son[p][a];
        else {return 0;}
        //p = son[p][a];
    }
    return p;
}

void dfs(int l){
    bool aaa = false;
    int i;
    while(cnt[l] > 0) {
        for (int i = 0; i < str1.size(); i++) {
            cout << str1[i];
        }
        cnt[l]--;
        cout << '\n';
    }
    for( i = 0; i < 26; i++){
        if(son[l][i] != 0) {
            char a = 'a' + i;
            str1.push_back(a);
            aaa = true;
            while(cnt[l] > 0) {
                for (int i = 0; i < str1.size(); i++) {
                    cout << str1[i];
                }
                cnt[l]--;
                cout << '\n';
            }
            dfs(son[l][i]);
            str1.pop_back();
        }
    }
    //if(i == 26 ){
    while(cnt[l] > 0) {
        for (int i = 0; i < str1.size(); i++) {
            cout << str1[i];
        }
        cnt[l]--;
        cout << '\n';
    }
    //}
}

int main(){
    int n;
    cin >> n;

    while (n --){
        cin >> str;
        insert(str);
    }
    cin >> str;
    for(int i = 0 ; i < str.size(); i++){
        str1.push_back(str[i]);
    }
    int l = query(str);
    dfs(l);

}