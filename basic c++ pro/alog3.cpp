//
// Created by 10154 on 2022/12/13.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int num0, num1;

void count1(string str){
    num0 = 0;
    num1 = 0;
    for(int i = 0; i < str.length(); i ++){
        if(str[i] == '0')
            num0 ++;
        else
            num1 ++;
    }
}

int main()
{
    int strslen111, m, n;
    int strlen[810];
    int dp[212][212];
    string str[810];
    cin >> strslen111;
    cin >> m >> n;
    for(int i = 0; i < strslen111 ; i ++){
        cin >> strlen[i];
    }
    for(int i = 0; i < strslen111 ; i ++){
        cin >> str[i];
    }

    for(int count = 0; count < strslen111; count ++){
        count1(str[count]);
        for (int j = m; j >= num0; j--) {
            for (int k = n; k >= num1; k--) {
                dp[j][k] = max(dp[j][k], dp[j - num0][k - num1] + 1);
            }
        }
    }
    cout << dp[m][n];
}

