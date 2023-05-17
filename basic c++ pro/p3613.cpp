//
// Created by 10154 on 2023/5/14.
//

#include "iostream"
#include "vector"
#include "utility"
#include "stdio.h"

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

using namespace std;

struct node{
    vector<pair<int, int>> dongxi;
};

struct node lianbiao[100005];

int chazhao(int b, int c){
    for(int i = lianbiao[b].dongxi.size() - 1; i >=0; i--){
        if(lianbiao[b].dongxi[i].first == c) {
            printf("%d\n", lianbiao[b].dongxi[i].second);
            return 0;
        }
    }
}


int main(){
   int n, q;
   cin >> n >> q;
   int a, b, c, d;
   for(int i = 0; i < q; i++){
       scanf("%d", &a);
       if(a != 2){
           scanf("%d%d%d", &b, &c,&d);
           lianbiao[b].dongxi.push_back({c, d});
       }
       else{
           scanf("%d%d", &b, &c);
           chazhao(b, c);
       }
   }
}