//
// Created by 10154 on 2022/10/10.
//

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long f[20];
string str;
int num;
int n, k;
long long x;

void jie_cheng(int n)
{
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++) f[i] = f[i - 1] * i;
}

int kangtuo()
{
    int ans = 1;
    int len = str.length();
    for(int i = 0; i < len; i++){
        int tmp = 0;

        for(int j = i + 1; j < len; j++){
            if(str[i] > str[j]) tmp++;
        }

        ans += tmp * f[len - i - 1];
    }
    return ans;
}

vector<char> vec;
void rev_kangtuo(int k)
{
    int n = vec.size(), len = 0;
    string ans = "";
    k--;
    for(int i = 1; i <= n; i++){
        int t = k / f[n - i];
        k %= f[n - i];
        ans += vec[t] ;
        vec.erase(vec.begin() + t);
    }
    cout << ans << '\n';
}

int main()
{
    jie_cheng(10);
    str.reserve(21);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    x = kangtuo() + k;
    for(int i = 1; i <= 10; i++){
        if(x / f[i] == 0){
            num = i;
            break;
        }
    }
    for(int i = 1; i <= num; i++){
        vec.push_back(i + '0');
    }
    rev_kangtuo(x);
}