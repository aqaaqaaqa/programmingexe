//
// Created by 10154 on 2023/6/15.
//

#include "iostream"
#include "string.h"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 5010;

int g[N][N];
int dist[N];
bool st[N];
int n, m;
int x, y, z;
int res;


int prim(){
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
        }
        if(i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if(i) res += dist[t];

        st[t] = true;

        for(int j = 1; j <= n; j++){
            dist[j] = min( dist[j], g[t][j]);
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--){
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    if(prim() == 0x3f3f3f3f){cout << "orz";}
    else cout << res;

}

