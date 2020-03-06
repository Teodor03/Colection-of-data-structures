#include<iostream>
using namespace std;

const int Max_N=1000000;

struct seg_tree_n{
int sum;
int update_addings;
};

int a [Max_N];
int n;

seg_tree_n segment_main [4*Max_N];

void build_seg_tree(int l,int r,int i){
if(l==r){
    segment_main[i].sum=a[r];
    return;
}
int mid=(l+r)/2;
build_seg_tree(l,mid,2*i+1);
build_seg_tree(mid+1,r,2*i+2);
segment_main[i].sum=segment_main[2*i+1].sum+segment_main[2*i+2].sum;
return;
}

int find_sum(int l,int r,int l_need,int r_need,int i){
if(l==l_need and r==r_need){
    return segment_main[i].sum+segment_main[i].update_addings;
}
int mid=(l+r)/2;
if(r_need<mid+1){
    return find_sum(l,mid,l_need,r_need,2*i+1);
}
if(l_need>mid){
    return find_sum(mid+1,r,l_need,r_need,2*i+2);
}
return find_sum(l,mid,l_need,mid,2*i+1)+find_sum(mid+1,r,mid+1,r_need,2*i+2);
}

void range_update(int l,int r,int l_need,int r_need,int added,int i){
if(l==l_need and r==r_need){
    segment_main[i].update_addings+=added;
    return;
}
int mid=(l+r)/2;
if(r_need<mid+1){
    range_update(l,mid,l_need,r_need,added,2*i+1);
}
if(l_need>mid){
    range_update(mid+1,r,l_need,r_need,added,2*i+2);
}
range_update(l,mid,l_need,mid,added,2*i+1);
range_update(mid+1,r,mid+1,r_need,added,2*i+2);
return;
}


int main(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
build_seg_tree(0,n-1,0);
//cout<<find_sum(0,n-1,3,5,0);
return 0;
}
