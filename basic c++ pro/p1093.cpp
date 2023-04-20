//
// Created by 10154 on 2023/4/14.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;

 typedef struct{
    int id;
    int yu;
    int shu;
    int yin;
    int sum;
} student;

student *temp = new student[N];

void swap(student *a, student *b){
    a->sum = b->sum;
    a->yu = b->yu;
    a->shu = b->shu;
    a->yin = b->yin;
    a->id = b->id;
}

 void merge_sort (student *p, int l, int r){
     if(l >= r) return;
     int mid = (l + r) >> 1;

     merge_sort(p, l ,mid);
     merge_sort(p, mid + 1, r);

     int i = l, j = mid + 1, k = 0;
     while(i <= mid && j <= r){
         if(p[i].sum < p[j].sum) swap(&temp[k++], &p[i++]);
         else if (p[i].sum > p[j].sum) swap(&temp[k++], &p[j++]);
         else{
             if(p[i].yu < p[j].yu) swap(&temp[k++], &p[i++]);
             else if(p[i].yu > p[j].yu) swap(&temp[k++], &p[j++]);
             else{
                 if(p[i].id > p[j].id) swap(&temp[k++], &p[i++]);
                 else if(p[i].id < p[j].id) swap(&temp[k++], &p[j++]);
             }
         }
     }
     while (i <= mid) swap(&temp[k++], &p[i++]);
     while (j <= r) swap(&temp[k++], &p[j++]);

     for(i = l, j = 0; i <= r; i++, j++) swap(&p[i], &temp[j]);
 }

int main(){
    student *p = new student[N];
    int n;
    scanf("%d", &n);
    int yu1, shu1, yin1;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&yu1,&shu1,&yin1);
        p[i].id = i + 1;
        p[i].yu = yu1;
        p[i].shu = shu1;
        p[i].yin = yin1;
        p[i].sum = yu1 + shu1 + yin1;
    }

    merge_sort(p, 0, n - 1);

    for(int i = 0; i < 5; i++){
        cout << p[n - 1 - i].id << ' ' << p[n - 1 - i].sum << endl;
    }

}