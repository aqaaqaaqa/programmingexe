//
// Created by 10154 on 2023/5/18.
//

#include "iostream"
#include "cstdio"
#include "algorithm"
#include "vector"

using namespace std;

const int N = 1e6 + 10;

char s[N], p[N];
int l1 = 1, l2 = 1, ne[N]= {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s + 1 >> p + 1;
    while(s[l1] != '\0'){
        l1++;
    }
    while(p[l2] != '\0'){
        l2++;
    }
    l1--;
    l2--;
    for(int i = 2, j = 0; i <= l2; i++){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    for(int i = 1, j = 0; i <= l1; i++){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == l2){
            cout << i - j + 1 << endl;
            j = ne[j];
        }
    }

    for(int i = 1; i <= l2 ; i++ ){
        cout << ne[i] << ' ';
    }

}