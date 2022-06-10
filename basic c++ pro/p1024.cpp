//
// Created by 10154 on 2022/5/29.
//
#include "iostream"

using namespace std;

double a,b,c,d;

double function(double x){
    return a*x*x*x + b*x*x + c*x +d;
}

void bsearch(double l,double r){
    while((r - l) > 1e-4){
        double mid = (l + r)/2;
        if(function(mid) * function(l) > 0 && function(mid) * function(r) > 0) return;
        if(function(mid) * function(l) < 0) r = mid;
        else l = mid;
    }
    printf("%.2lf ",l);
}


int main(){
    cin >> a >> b >> c >> d;
    int l = -100, r = 100;
    for (int i = -100; i <= 100 ; i++){
        bsearch(i, i + 1);
    }
}