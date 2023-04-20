//
// Created by 10154 on 2022/11/28.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int sk[100000], lab[2 * 100000];
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        cin >> sk[i];
    }
    for(int i = 0; i < 2 * M; i ++){
        cin >> lab[i];
    }
    for(int i = 0; i < M ; i ++){
        int maxsum = -21474836;
        int sum = 0;
        for (int j = lab[2 * i]; j <= lab[2 * i + 1]; j ++){
            sum = max(sum + sk[j], sk[j]);
            maxsum = max(maxsum, sum);
        }
        cout << maxsum;
        if(i < M - 1)
            cout << endl;
    }
}
