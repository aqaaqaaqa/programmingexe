//
// Created by 10154 on 2023/7/9.
//

#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"

using namespace std;
int n ;

int main(){
    priority_queue<int, vector<int>, greater<int>> heap;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        heap.push(a);
    }

    int ans = 0;

    while (heap.size() != 1){
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        ans = ans + a + b;
        heap.push(a + b);
    }

    cout << ans;
    return 0;
}