#include<iostream>
#include<algorithm>
using namespace std;

// add extra null and see weirdness
const int Max_N=100000;

struct segment_tree{
    // update single value
    struct node{
        int _max;
        node(){_max=0;}
    };

    node arr [4*Max_N];

    void update_node(int i){
        arr[i]._max=max(arr[2*i+1]._max,arr[2*i+2]._max);
        return;
    }


    void update(int upd_ind,int new_val,int i,int l,int r){
        if(l==r){
            arr[i]._max=new_val;
            return;
        }
        int m=(l+r)/2;
        if(upd_ind<=m){
            update(upd_ind,new_val,2*i+1,l,m);

        }else{
            update(upd_ind,new_val,2*i+2,m+1,r);
        }
        update_node(i);
        return;
    }

    int find_max(int l_q,int r_q,int i,int l,int r){
        if(l_q==l and r_q==r){
            return arr[i]._max;
        }
        int m=(l+r)/2;
        if(r_q<=m){
            return find_max(l_q,r_q,2*i+1,l,m);
        }
        if(m<l_q){
            return find_max(l_q,r_q,2*i+2,m+1,r);
        }
        return max(find_max(l_q,m,2*i+1,l,m),find_max(m+1,r_q,2*i+2,m+1,r));
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    segment_tree seg;
    seg.update(5,8,0,0,9);
    seg.update(6,7,0,0,9);
    cout<<seg.find_max(0,9,0,0,9);
    return 0;
}
