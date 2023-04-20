#include <iostream>
using namespace std;
int primes[20005] = {2};
bool isnotprime[20005] = {1, 1, 0, 0, 1, 0, 1, 0};
int exp[20005][20005];
int k = 1;

int prime(int n){
    int i, j;
    for (i = 3; i * i <= n; i += 2){
        if (!isnotprime[i]){
            primes[k ++] = i;
            for (j = i; i * j <= n; j += 2){
                isnotprime[i * j] = true;
            }
        }
    }
    for (; i <= n; i += 2){
        if (!isnotprime[i]) primes[k ++] = i;
    }
}

void init(int n){
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k && primes[j] <= n; j++){
            if(i % primes[j] == 0){
                int t = i;
                while(t % primes[j] == 0){
                    t /= primes[j];
                    exp[i][j]++;
                }
            }
            exp[i][j] += exp[i - 1][j];
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    if(m == 0) {
        cout << 0;
        return 0;
    }
    prime(20004);
    init(20004);
    int ant[20004];
    for(int i = 0; i < k; i ++){
        ant[i] = exp[n][i] - exp[m][i] - exp[n - m][i];
    }
    long long ans = 0;
    for(int i = 0; i < k; i++) {
        if (ant[i] != 0)
            ans++;
    }
    cout << ans;
}