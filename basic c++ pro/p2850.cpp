//
// Created by 10154 on 2023/6/12.
//

#include "iostream"
#include "algorithm"
#include "queue"
#include "string.h"

using namespace std;

const int N = 5e4 + 10;

int T, n, m, w1;
int h[N], e[N], ne[N], w[N], idx;
int dist[N], cnt[N];
bool st[N];
bool falg;
void insert(int a, int b, int w2){
    e[idx] = b;
    ne[idx] =h[a];
    w[idx] = w2;
    h[a] = idx ++;
}

void spfafuhuan(int s){
    queue<int> que;

    memset(dist, 0x3f, sizeof dist);

    //for(int i = 1; i <= n; i++){
    que.push(s);
    st[s] = true;
    dist[s] = 0;
    //}
    while(que.size()){
        auto q = que.front();
        que.pop();
        st[q] = false;

        for(int i = h[q]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[q] + w[i]){
                dist[j] = dist[q] + w[i];
                cnt[j] = cnt[q] + 1;
                if(cnt[s] >= n && dist[s] < 0) {falg = true; return;}
                if(!st[j]){
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
    falg = false;

}

int main(){
    cin >> T;
    int u, v, p;
    while(T--){
        memset(h, -1 ,sizeof h);
        cin >> n >> m >> w1;
        while(m--){
            cin >> u >> v >> p;
            insert(u, v, p);
            insert(v, u, p);
        }
        while (w1--){
            cin >> u >> v >> p;
            insert(u, v, -p);
        }
        for(int i = 1 ; i <= n; i++) {
            spfafuhuan(i);
            if(falg){
                cout << "YES" << '\n';
                break;
            }
        }
        if(!falg) {
            cout << "NO" << '\n';
        }
        idx = 0;
        falg = false;
        memset(cnt, 0, sizeof cnt);
    }
}