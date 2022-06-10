//
// Created by 10154 on 2022/6/6.
//

#include "iostream"

const int N = 200010;

using  namespace std;

int q[N];
long long s[N] = {0};

int main(){
    int n;
    cin >> n;
    s[0] = 0;
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d", &q[i]);
    }

    for(int i = 1 ; i <= n ; i ++){
        s[i] = s[i - 1] + q[i];
    }

    long long max = q[1];
    int dis = 0;
    while(dis <= n) {
        for (int i = 1 ; i <= n ; i ++){
            if((i + dis) <= n) {
                long long temp = s[i + dis] - s[i - 1];
                if (temp > max) max = temp;
            }
            else
                break;
        }
        dis ++;
    }
    cout << max;
}