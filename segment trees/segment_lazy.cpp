#include<iostream>
using namespace std;

const int Max_N=100000;

//lazy add value
//queue for maximum in range

struct segment_tree{

    struct node{
        int _max;
        int lazy_add;

        node(){
            _max=0;
            lazy_add=0;
            return;
        }

    };

    node arr [Max_N];

    void push(int i){
        arr[2*i+1]._max+=arr[i].lazy_add;
        arr[2*i+2]._max+=arr[i].lazy_add;
        arr[2*i+1].lazy_add+=arr[i].lazy_add;
        arr[2*i+2].lazy_add+=arr[i].lazy_add;
        arr[i].lazy_add=0;
        return;
    }

    void update(int lq,int rq,int upd,int i,int l,int r){
        if(lq==l and rq==r){
            arr[i].lazy_add+=upd;
            arr[i]._max+=upd;
            return;
        }
        int m=(l+r)/2;
        push(i);
        if(rq<=m){
            update(lq,rq,upd,2*i+1,l,m);
            arr[i]._max=max(arr[2*i+1]._max,arr[2*i+2]._max);
            return;
        }
        if(m<lq){
            update(lq,rq,upd,2*i+2,m+1,r);
            arr[i]._max=max(arr[2*i+1]._max,arr[2*i+2]._max);
            return;
        }
        update(lq,m,upd,2*i+1,l,m);
        update(m+1,rq,upd,2*i+2,m+1,r);
        arr[i]._max=max(arr[2*i+1]._max,arr[2*i+2]._max);
        return;
    }

    int find_max(int lq,int rq,int i,int l,int r){
        if(lq==l and rq==r){
            return arr[i]._max;
        }
        int m=(l+r)/2;
        push(i);
        if(rq<=m){
            return find_max(lq,rq,2*i+1,l,m);
        }
        if(m<lq){
            return find_max(lq,rq,2*i+2,m+1,r);
        }
        return max(find_max(lq,m,2*i+1,l,m),find_max(m+1,rq,2*i+2,m+1,r));
    }

};



int main(){
    ios_base::sync_with_stdio(false);
    segment_tree seg;
    seg.update(1,4,2,0,0,9);
    seg.update(4,6,4,0,0,9);
    for(int i=0;i<10;i++){
        cout<<seg.find_max(i,i,0,0,9)<<endl;
    }
    cout<<seg.find_max(0,4,0,0,9);
    return 0;
}
