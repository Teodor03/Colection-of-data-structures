#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;

const int Inf=2147483647;

struct treap_node{

    int val,y;
    treap_node * l, * r;

    treap_node(int v): val{v}, y{rand()}, l{nullptr}, r{nullptr} {}

};

class treap{
    public:

    treap_node * root;


    treap(){
        srand(time(NULL));
        root = nullptr;
        //root = new treap_node(v);
    }

    void destroy(treap_node * curr){
        if(!curr)
            return;
        destroy(curr->l);
        destroy(curr->r);
        delete curr;
        return;
    }

    ~treap(){
        destroy(root);
    }

    pair<treap_node *, treap_node *> split(treap_node * c_i,int c_v){
        if(!c_i){
            return {nullptr,nullptr};
        }
        if((c_i->val)==c_v){
            pair<treap_node *, treap_node *> ans = {c_i->l,c_i->r};
            delete c_i;
            return ans;
        }
        if(c_v<(c_i->val)){
            auto res = split(c_i->l,c_v);
            c_i->l=res.second;
            return {res.first,c_i};
        }
        if((c_i->val)<c_v){
            auto res = split(c_i->r,c_v);
            c_i->r=res.first;
            return {c_i,res.second};
        }
    }

    treap_node * _merge(treap_node * ll,treap_node * rr){
        if(!ll)return rr;
        if(!rr)return ll;
        if(ll->y>rr->y){
            ll->r = _merge(ll->r,rr);
            return ll;
        }
        if(ll->y<=rr->y){
            rr->l = _merge(ll,rr->l);
            return rr;
        }
    }

    void _insert(int val){
        if(!root){
            root = new treap_node(val);
            root->y = Inf;
            return;
        }
        treap_node * curr=root;
        treap_node * par=nullptr;
        bool dir=false;//f = l ; t = r
        treap_node * added = new treap_node(val);
        while(1){
            if(!curr){
                if(dir){
                    par->r = added;
                }else{
                    par->l = added;
                }
                return;
            }
            if(curr->val==added->val){
                return;
            }
            if(added->y > curr->y){
                auto rem = split(curr,added->val);
                added->l=rem.first;
                added->r=rem.second;
                if(par->val<added->val){
                    par->r=added;
                }else{
                    par->l=added;
                }
                return;
            }
            if(curr->val>added->val){
                par=curr;
                curr=curr->l;
                dir=false;
            }else{
                par=curr;
                curr=curr->r;
                dir=true;
            }
        }
    }

    void _erase(int val){
        auto t = split(root,val);
        _merge(t.first,t.second);
    }

    bool _find(int val,treap_node * curr){
        if(!curr)
            return false;
        if(curr->val==val)
            return true;
        if(val<curr->val){
            return _find(val,curr->l);
        }else{
            return _find(val,curr->r);
        }
    }

};

int main (){
    ios_base::sync_with_stdio(false);
    treap * new_treap=new treap();
    treap_node tr(8);
    new_treap->_insert(8);
    new_treap->_insert(3);
    new_treap->_insert(3);
    new_treap->_insert(4);
    new_treap->_insert(6);
    cout<<new_treap->_find(8,new_treap->root);
    delete new_treap;
    return 0;
}
