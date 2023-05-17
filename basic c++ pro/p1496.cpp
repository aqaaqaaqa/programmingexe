//
// Created by 10154 on 2023/5/7.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"

using namespace std;

typedef pair<int, int> tll;
vector<tll> chuan;
vector<int> num;
const int N = 60000;
int a1 = 0;

int find(int x){
    int l = 0, r = num.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(num[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}


int main(){
    int n;
    int length = 0;
    int a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        chuan.push_back({a, b});
        num.push_back(a);
        num.push_back(b);
    }
    sort(chuan.begin(), chuan.end());
    chuan.erase(unique(chuan.begin(), chuan.end()), chuan.end());
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int l = -2e9, r = -2e9;
    for(auto item: chuan){
        int x1 = item.first;
        int x2 = item.second;
        if(r < x1){
            if(l != -2e9) a1 += r - l;
            l  = x1, r = x2;
        }
        else r = max(r, x2);
    }
    if(l != -2e9) a1 += r - l;
    cout << a1;
}