//
// Created by 10154 on 2022/10/9.
//
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> per(21);
int n, k;

void reverse(int first, int last){
    last--;
    while (first < last){
        swap(per[first ++], per[last --]);
    }
}

int getper(){
    int last = n - 2;
    while(last >= 0 && per[last] >= per[last + 1])
        --last;
    if(last == -1){
        reverse(0, n);
        //reverse(&per[0], &per[n - 1]);
        return 0;
    }
    int first = n - 1;
    while(per[first] <= per[last]){
        --first;
    }
    swap(per[first], per[last]);
    //reverse(&per + last + 1, &per + n - 1);
    reverse(last + 1, n);
}



int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> per[i];
    }
    while(k -- > 0){
        getper();
    }
    for(int i = 0; i < n; i ++){
        cout << per[i];
        if(i != n - 1)
            cout << ' ';
    }
}