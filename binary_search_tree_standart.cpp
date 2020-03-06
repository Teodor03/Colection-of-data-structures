#include<iostream>
#include<vector>
using namespace std;

struct elem{
int val;
int left;
int right;
int par;
};

int num=0;
vector<elem> bin_s_t;

void push(int val){
int curr=0;
if(num==0){
    bin_s_t.push_back({val,-1,-1,-1});
    num++;
    return;
}
while(1){
    if(val==bin_s_t[curr].val){
        return;
    }
    if(val<bin_s_t[curr].val){
        if(bin_s_t[curr].left==-1){
            bin_s_t.push_back({val,-1,-1,curr});
            bin_s_t[curr].left=bin_s_t.size()-1;
            num++;
            return;
        }else{
            curr=bin_s_t[curr].left;
            goto end_loop;
        }
    }
    if(bin_s_t[curr].val<val){
        if(bin_s_t[curr].right==-1){
            bin_s_t.push_back({val,-1,-1,curr});
            bin_s_t[curr].right=bin_s_t.size()-1;
            num++;
            return;
        }else{
            curr=bin_s_t[curr].right;
            goto end_loop;
        }
    }
    end_loop:;
}
return;
}

bool _search(int s_val){
int curr=0;
while(curr!=-1){
    if(bin_s_t[curr].val==s_val){
        return true;
    }
    if(bin_s_t[curr].val<s_val){
        curr=bin_s_t[curr].right;
    }else{
        curr=bin_s_t[curr].left;
    }
}
return false;
}

int main(){
push(0);
push(-1);
push(-3);
push(8);
push(4);
cout<<_search(4);
return 0;
}
