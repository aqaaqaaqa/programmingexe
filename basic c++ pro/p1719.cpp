//
// Created by 10154 on 2022/6/8.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N = 121;
int mar[N][N];
int s[N][N] = {0};


int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            scanf("%d",&mar[i][j]);
        }
    }

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i- 1][j - 1] + mar[i][j];
        }
    }

    int maxmen = mar[1][1],temp;
    for(int i = 1 ; i < n ; i ++){
        for(int j = 1 ; j < n ; j ++){
            for(int r = i ; r <= n ; r ++)
                for(int b = j ; b <= n ; b ++)
                {
                    temp=s[r][b]-s[r][j - 1]-s[i - 1][b]+s[i - 1][j - 1];
                    maxmen = max(maxmen, temp);
                }
        }
    }
    cout << maxmen;
}