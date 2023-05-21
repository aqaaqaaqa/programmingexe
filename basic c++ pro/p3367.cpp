
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

int jihe[10010];

int find1(int x){
    if(jihe[x] != x) jihe[x] = find1(jihe[x]);
    else return jihe[x];
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) jihe[i] = i;
    int z, x, y;
    while(m -- ){
        cin >> z >> x >> y;
        if(z == 1){
            jihe[find1(x)] = find1(y);
        }
        else{
            int m = find1(x), n = find1(y);
            if(find1(x) == find1(y)) printf("Y\n");
            else printf("N\n");
        }
    }
}


