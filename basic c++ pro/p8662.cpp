//
// Created by 10154 on 2023/5/30.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
#include "cstdio"
#include "string.h"

using namespace std;
const int N = 1010;
typedef pair<int, int> inn;
int daobianhao[N][N];
char haiyu[N][N];
inn haiyudian[N * N];
int yuandao, xiandao;
int n;

int bfs(){
    int hh = 0, tt = 0; //已经有一个点在队列里了
    haiyudian[0] = {0, 0};
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0 , 1, 0, -1};
    while(hh <= tt){
        auto t = haiyudian[hh ++];
        for(int i = 0; i< 4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && y >= 0 && x < n && y < n && haiyu[t.first][t.second] == '#' && haiyu[x][y] == '.'){
                haiyu[t.first][t.second] = '.';
                haiyudian[++ tt] = {x, y};
            }
        }
    }
}

int bfs2(){
    int max = 1;
    bool lm = false;
    int hh = 0, tt = 0; //已经有一个点在队列里了
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0 , 1, 0, -1};
    while(hh <= tt){
        auto t = haiyudian[hh ++];
        for(int i = 0; i< 4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && y >= 0 && x < n && y < n && haiyu[t.first][t.second] == '#' && haiyu[x][y] == '#' ){
                daobianhao[x][y] = max;
                lm = true;
                haiyudian[++ tt] = {x, y};
            }
            if(!lm) {
                max++;
                lm = false;
            }
            else{
                lm = false;
            }
        }
    }
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    memset(daobianhao, -1, sizeof daobianhao);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> haiyu[i][j];
        }
    }
    bfs2();


    cout << bfs();
}