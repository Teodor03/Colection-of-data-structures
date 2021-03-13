#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct segment_2d_tree_standart{

    struct node{
        int max;
        node(){max=0;}
    };

    int size_x,size_y;
    vector<vector<node>> arr;

    segment_2d_tree_standart(int sx,int sy){
        size_x=sx;
        size_y=sy;
        arr.resize(4*sx);
        for(int i=0;i<4*sx;i++){
            arr[i].resize(4*sy);
        }
        return;
    }

    int upd_x,upd_y,upd_v;

    void update_y(int i_x,bool is_lin_x,int i_y,int l,int r){
        cout<<"Update Y : "<<i_x<<" "<<i_y<<" "<<l<<" "<<r<<endl;
        if(l==r){
            if(is_lin_x){
                arr[i_x][i_y].max=upd_v;
            }else{
                arr[i_x][i_y].max=max(arr[2*i_x+1][i_y].max,arr[2*i_x+2][i_y].max);
            }
            return;
        }
        int m=(l+r)/2;
        if(upd_y<=m){
            update_y(i_x,is_lin_x,2*i_y+1,l,m);
        }else{
            update_y(i_x,is_lin_x,2*i_y+2,m+1,r);
        }
        arr[i_x][i_y].max=max(arr[i_x][2*i_y+1].max,arr[i_x][2*i_y+2].max);
        return;
    }

    void update_x(int i_x,int l,int r){
        cout<<"Update X : "<<i_x<<" "<<l<<" "<<r<<endl;
        if(l==r){
            update_y(i_x,true,0,0,size_y-1);
            return;
        }
        int m=(l+r)/2;
        if(upd_x<=m){
            update_x(2*i_x+1,l,m);
        }else{
            update_x(2*i_x+2,m+1,r);
        }
        update_y(i_x,false,0,0,size_y-1);
        return;
    }

    void update(int up_x,int up_y,int up_v){
        upd_x=up_x;
        upd_y=up_y;
        upd_v=up_v;
        update_x(0,0,size_x-1);
    }

    int find_y(int y_l,int y_r,int i_x,int i_y,int l,int r){
        if(y_l==l and y_r==r){
            return arr[i_x][i_y].max;
        }
        int m=(l+r)/2;
        if(y_r<=m){
            return find_y(y_l,y_r,i_x,2*i_y+1,l,m);
        }
        if(m<y_l){
            return find_y(y_l,y_r,i_x,2*i_y+2,m+1,r);
        }
        return max(find_y(y_l,m,i_x,2*i_y+1,l,m),find_y(m+1,y_r,i_x,2*i_y+2,m+1,r));
    }

    int find_x(int x_l,int x_r,int y_l,int y_r,int i_x,int l,int r){
        if(x_l==l and x_r==r){
            return find_y(y_l,y_r,i_x,0,0,size_y-1);
        }
        int m=(l+r)/2;
        if(x_r<=m){
            return find_x(x_l,x_r,y_l,y_r,2*i_x+1,l,m);
        }
        if(m<x_l){
            return find_x(x_l,x_r,y_l,y_r,2*i_x+2,m+1,r);
        }
        return max(find_x(x_l,m,y_l,y_r,2*i_x+1,l,m),find_x(m+1,x_r,y_l,y_r,2*i_x+2,m+1,r));
    }

    int find_max(int x_l,int x_r,int y_l,int y_r){
        return find_x(x_l,x_r,y_l,y_r,0,0,size_x-1);
    }

};



int main(){
    ios_base::sync_with_stdio(false);
    segment_2d_tree_standart seg(8,8);
    seg.update(3,3,9);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<seg.find_max(j,j,i,i)<<" ";
        }
        cout<<endl;
    }
    cout<<seg.find_max(5,6,5,7);
    return 0;
}
