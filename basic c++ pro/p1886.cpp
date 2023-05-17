#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int a[1000010];
int que[1000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;

    cin >> n >> k;
    for(int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    int tt = -1, hh = 0;

    for(int i = 0; i < n; i++){
        if(hh <= tt && que[hh] < i - k + 1 ) hh ++;
        while(hh <= tt && a[que[tt]] >= a[i]) tt--;
        que[++tt] = i;
        if(i >= k - 1) cout << a[que[hh]] << ' ';
    }
    cout << endl;

    tt = -1, hh = 0;
    for(int i = 0; i < n; i++){
        if(hh <= tt && que[hh] < i - k + 1 ) hh ++;
        while(hh <= tt && a[que[tt]] <= a[i]) tt--;
        que[++tt] = i;
        if(i >= k - 1) cout << a[que[hh]] << ' ';
    }
    cout << endl;

}
