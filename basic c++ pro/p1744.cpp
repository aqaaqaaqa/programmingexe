//
// Created by 10154 on 2023/6/12.
//

#include "iostream"
#include "queue"
#include "algorithm"
#include "string.h"
#include "utility"
#include "math.h"

using namespace std;

int const N = 10010;

typedef pair<int, int> PII;


int n, m;
int s, t;

int h[N], e[N], ne[N], idx;
double w[N], dist[N];
PII zuobiao[N];
bool st[N];

double distance(int a, int b){
    int dx = abs(zuobiao[a].first - zuobiao[b].first);
    int dy = abs(zuobiao[a].second - zuobiao[b].second);

    return sqrt(dx * dx + dy * dy);
}

void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = distance(a, b);
    h[a] = idx++;
}

void spfa(int s, int t){
    for(int i = 1; i <= n; i ++) dist[i] = 1000000000.0;

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    st[s] = true;

    while(q.size()){
        auto jk = q.front();
        q.pop();
        st[jk] = false;
        for(int i = h[jk]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[jk] + w[i]) {
                dist[j] = dist[jk] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    printf("%.2f", dist[t]);
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> zuobiao[i].first >> zuobiao[i].second;
    }
    memset(h, -1, sizeof h);
    cin >> m;

    for(int i = 1; i <= m; i++){
        cin >> s >> t;
        insert(s, t);
        insert(t, s);
    }

    cin >> s >> t;
    spfa(s, t);
}