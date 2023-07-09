//
// Created by 10154 on 2023/7/8.
//

#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 5e4 + 10;
int max_r[N];
int ans[N];
struct Niu{
    int l, r, zu, num;
    bool operator< (const Niu &W){
        return l < W.l;
    }
} niu[N];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> niu[i].l >> niu[i].r;
        niu[i].num = i + 1;
    }

    sort(niu, niu + n);

    int cnt = 1;
    bool flag = false;
    for(int i = 0; i < n; i++){
        flag = false;
        if(cnt == 1){
            max_r[cnt] = niu[i].r;
            ans[niu[i].num] = cnt;
            cnt++;
            continue;
        }
        for(int j = cnt - 1; j >= 1; j--){
            if(niu[i].l > max_r[j]){
                max_r[j] = max(max_r[j], niu[i].r);
                ans[niu[i].num] = j;
                flag = true;
                break;
            }
        }
        if(!flag){
            max_r[cnt] = niu[i].r;
            ans[niu[i].num] = cnt;
            cnt++;

        }
    }

    cout << cnt - 1 << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}



