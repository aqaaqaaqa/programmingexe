//
// Created by 10154 on 2023/5/16.
//

#include "iostream"
#include "cstdio"
#include "vector"
#include "string"

using namespace std;

const int N = 1e6 + 10;

unsigned long long int stk[N];
unsigned long long int tt = 0;

void push(int x){
    stk[tt++] = x;
}

void pop(){
    if(tt == 0)
        printf("Empty\n");
    else
        tt--;
}

void query(){
    if(tt == 0)
        printf("Anguei!\n");
    else
        printf("%llu\n", stk[tt]);
}

void size(){
    printf("%llu\n", tt);

}



int main(){
    unsigned long long int t, n;
    string a;
    cin >> t;
    for(int i = 0; i < t; i++){
        scanf("%llu", &n);
        for(int j = 0; j < n; j++) {
            cin >> a;
            if(a == "push"){
                int x;
                cin >> x;
                push(x);
            }
            else if(a == "query"){
                query();
            }
            else if(a == "size"){
                size();
            }
            else
                pop();
        }
        tt = 0;
    }
}