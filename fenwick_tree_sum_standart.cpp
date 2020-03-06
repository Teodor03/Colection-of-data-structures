#include<iostream>
using namespace std;

const int Max_N=100000;

int n;
int a[Max_N];
int BIT [Max_N];

void add_Fenwick(int i,int added){
for(;i<n;i=(i|(i+1))){
    BIT[i]+=added;
}
return;
}

void init_Fenwick(){
for(int i=0;i<n;i++){
    add_Fenwick(i,a[i]);
}
return;
}

int sum_Fenwick(int r){
int res=0;
for(;r>-1;r=((r&(r+1))-1)){
    res+=BIT[r];
}
return res;
}

/*
8
1 7 11 5 8 13 17 4
*/

int main(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
init_Fenwick();
cout<<sum_Fenwick(4)<<endl;
add_Fenwick(1,-8);
cout<<sum_Fenwick(4);
return 0;
}
