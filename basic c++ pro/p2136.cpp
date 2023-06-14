//
// Created by 10154 on 2023/6/14.
//
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
int min1, min2;
void insert(int a, int b, int w2){
    e[idx] = b;
    ne[idx] =h[a];
    w[idx] = w2;
    h[a] = idx ++;
}

void spfafuhuan(int s){
    queue<int> que;

    memset(dist, 0x3f, sizeof dist);
    que.push(s);
    st[s] = true;
    dist[s] = 0;
    if(s == 1) s = n;
    else s = 1;
    while(que.size()){
        auto q = que.front();
        que.pop();
        st[q] = false;
        for(int i = h[q]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[q] + w[i]){
                dist[j] = dist[q] + w[i];
                cnt[j] = cnt[q] + 1;
                //if(cnt[j] >= n) {falg = true; return;}
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
    int u, v, p;
        memset(h, -1 ,sizeof h);
        cin >> n >> m;
        while(m--){
            cin >> u >> v >> p;
            insert(u, v, -p);
        }
        spfafuhuan(1);
        min1 = dist[n];
        spfafuhuan(n);
        min2 = dist[1];
        if(falg){
            cout << "Forever love";
        }
        else{
            cout << min(min1, min2);
        }
}
