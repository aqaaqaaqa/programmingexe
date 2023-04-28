//
// Created by 10154 on 2023/4/27.
//

#include "iostream"

using namespace std;

int ditan[1010][1010] ={0};
int ditanqianzhui[1010][1010] ={0};
int n, m;

void insert(int x1, int y1, int x2, int y2, int c){
    ditan[x1][y1] += c;
    ditan[x2 + 1][y2 + 1] += c;
    ditan[x1][y2 + 1] -= c;
    ditan[x2 + 1][y1] -= c;
}

int main(){
    cin >> n >> m;
    int x1,y1,x2,y2;
    for(int i = 0; i < m ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2, 1);
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            ditanqianzhui[i][j] = ditanqianzhui[i - 1][j] + ditanqianzhui[i][j - 1] - ditanqianzhui[i - 1][j - 1]  + ditan[i][j];
        }
    }

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            cout << ditanqianzhui[i][j] << ' ';
        }
        cout << endl;
    }

}