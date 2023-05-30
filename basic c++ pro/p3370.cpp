//
// Created by 10154 on 2023/5/24.
//

#include "iostream"
#include "algorithm"
#include "string"
#include "vector"

using namespace std;

typedef unsigned long long ull;

const int p = 131;

ull h[10010];
vector<ull> hp;
string a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int i = 0;
    while(n--){
        cin >> a;
        for(int j = 0; j < a.size(); j++){
            h[i] = h[i] * p + (int)a[j];
        }
        hp.push_back( h[i]);
        h[i] = 0;
    }


    sort(hp.begin(), hp.end());
    hp.erase(unique(hp.begin(),hp.end()), hp.end());
    cout << hp.size();
}



#include "iostream"
#include "algorithm"
#include "string"
#include "vector"

using namespace std;

typedef unsigned long long ull;

const int N = 1e4 + 3, p = 13331;

ull h[10010][1510];
vector<ull> hp;
string a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int i = 0;
    while(n--){
        cin >> a;
        for(int j = 0; j < a.size(); j++){
            h[i][j + 1] = h[i][j] * p + (int)a[j];
        }
        hp.push_back( h[i][a.size() - 1]);
        i++;
    }

    sort(hp.begin(), hp.end());
    hp.erase(unique(hp.begin(),hp.end()), hp.end());
    cout << hp.size();
}
