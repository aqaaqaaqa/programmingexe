//
// Created by 10154 on 2023/5/30.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
#include "cstdio"
#include "string.h"
#include "set"

using namespace std;

const int N = 1010;
typedef pair<int, int> pii1;
char haiyu[N][N];
int bianhao[N][N];
pii1 que[N * N];
int yuandao, xiandao, n;
int num = 1;

int bfsbianhao(int x, int y){
    int tt = 0, hh = 0;
    que[0] = {x, y};
    bianhao[x][y] = num;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0 , 1, 0, -1};
    while(hh <= tt){
        pii1 t = que[hh ++];
        for(int i = 0; i < 4; i++){
            int xx = t.first + dx[i], yy = t.second + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && bianhao[xx][yy] == -5 && haiyu[xx][yy] == '#'){
                bianhao[xx][yy] = num;
                que[++ tt] = {xx, yy};
            }
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cin >> haiyu[i][j];
            bianhao[i][j] = -5;
        }
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(haiyu[i][j] == '#' && bianhao[i][j] == -5){
                bfsbianhao(i, j);
                num++;
            }
        }
    }
    num--;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(haiyu[i][j] == '#' && bianhao[i][j] != -5){
                int dx[4] = {-1, 0, 1, 0}, dy[4] = {0 , 1, 0, -1};
                for(int k = 0; k < 4; k++){
                    int xx = i + dx[k], yy = j + dy[k];
                    if(xx >= 0 && xx < n && yy >= 0 && yy < n  && haiyu[xx][yy] == '.'){
                        bianhao[i][j] = -5;
                    }
                }
            }
        }
    }

    set<int> bianhao2;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(bianhao[i][j] != -5){
                bianhao2.insert(bianhao[i][j]);
            }
        }
    }


    cout << num - bianhao2.size();
}