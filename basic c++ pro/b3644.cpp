//
// Created by 10154 on 2023/6/1.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string.h"

using namespace std;

const int N =10000;
int a;

int h[N], e[N], ne[N], idx = 1;
int rudu[N];
vector<int> top;

void insert(int hang, int x){
    e[idx] = x;
    ne[idx] = h[hang];
    h[hang] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    int que [N];
    for(int i = 1; i <= a; i++){
        if(rudu[i] == 0){
            que[++ tt] = i;
        }
    }

    while(tt >= hh){
        auto t = que[hh ++];
        top.push_back(t);
        for(int i = h[t]; i != -1; i = ne[i]){
            rudu[e[i]]--;
            if(rudu[e[i]] == 0){
                que[++ tt] = e[i];
            }
        }
    }

    for(int i = 0; i < top.size(); i++) cout << top[i]<< ' ';
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    int b = 1;
    cin >> n;
    a = n;
    memset(h, -1, sizeof h);
    while(n){
        while(true) {
            int x;
            cin >> x;
            if (x != 0) {
                insert(b, x);
                rudu[x]++;
            }
            else{
                b++;
                break;
            }
        }
        n--;
    }


    topsort();
}