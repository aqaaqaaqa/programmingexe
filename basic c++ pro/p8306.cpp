//
// Created by 10154 on 2023/5/20.
//

#include<bits/stdc++.h>

using namespace std;

const int N = 3e6 + 10;
int tree[N][65], con[N], idx;
char str[N];

int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}

void insert(char x[]){
    int q = 0;int len = strlen(str);
    for(int i = 0 ; i < len; i++){
        int b = getnum(x[i]);
        if(tree[q][b] == 0) tree[q][b] = ++idx;
        q = tree[q][b];
        con[q]++;
    }

}

void query(char x[]){
    int q = 0;int len = strlen(str);
    for(int i = 0 ; i < len; i++){
        int b = getnum(x[i]);
        if(tree[q][b] != 0 ) q = tree[q][b];
        else {printf("0\n"); return;}
    }
    printf("%d\n", con[q]);
}

int main(){
    int t;
    scanf("%d", &t);
    int n, q;
    while(t--){
        for(int i=0;i<=idx;i++)
            for(int j=0;j<=65;j++)
                tree[i][j]=0;
        for(int i=0;i<=idx;i++)
            con[i]=0;
        idx=0;
        for(int i=0;i<=idx;i++)
            for(int j=0;j<=122;j++)
                tree[i][j]=0;
        scanf("%d%d", &n, &q);
        while(n--){
            scanf("%s", str);
            insert(str);
        }
        while (q--){
            scanf("%s", str);
            query(str);
        }
    }
}