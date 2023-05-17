//
// Created by 10154 on 2023/5/16.
//

#include "iostream"
#include "cstdio"

using namespace std;

int que[100000], hh = 0, tt = -1;

void push(int x){
    que[++tt] = x;
}

void pop(){
    if(hh <= tt)
        hh++;
    else
        cout << "ERR_CANNOT_POP" << endl;
}

void query(){
    if(hh <= tt)
        cout << que[hh] << endl;
    else
        cout << "ERR_CANNOT_QUERY" << endl;
}

void size(){
    cout << tt - hh + 1 << endl;
}



int main (){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, t;
    cin >> n;

    while(n--){
        cin >> t;
        if(t == 1) {
            cin >> t;
            push(t);
        }
        else if ( t == 2){
            pop();
        }
        else if ( t == 3 ){
            query();
        }
        else if( t == 4 ){
            size();
        }
    }



}