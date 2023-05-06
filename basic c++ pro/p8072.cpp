//
// Created by 10154 on 2023/5/6.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "math.h"

using namespace std;

int main(){
    long long n, n1, n2;
    int num = 0;
    int i = 0;
    cin >> n;
    n1 = n;
    n2 = n;
    while (n != 0){
        n = n >> 1;
        i++;
    }
    for(int j = 0; j <= i; j++){
        if((n1 >> j & 1) == 1){
            num = j;
            break;
        }
    }
    num = i - num;
    if(n2 == pow(2, i - 1)) {i = i - 1; num = 0;}
    cout << (int)pow(2, i) << ' ' << num;
}
