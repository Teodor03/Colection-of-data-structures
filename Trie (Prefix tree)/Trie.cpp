#include<iostream>
#include<string>
using namespace std;


const int Max_number_of_nodes=1001;

struct node{
char character;
int son;
int next_brother;
};

node tree [Max_number_of_nodes];
int added_limit=1;

void initialise_node_tree(){
node root={(char) 0,-1,-1};
tree [0]=root;
}

void add_string(string added_string){
int index_of_current_node=0,current_searching_brother;
bool when_to_break=true;
bool have_found;
char current;
node adding_node;
for(int counter=0;counter<added_string.size();counter++){
current=added_string.at(counter);
if(tree[index_of_current_node].son==-1){
adding_node={current,-1,-1};
tree [added_limit]=adding_node;
tree[index_of_current_node].son=added_limit;
index_of_current_node=added_limit;
added_limit++;
}else{
current_searching_brother=tree[index_of_current_node].son;
while(when_to_break){
    if(tree[current_searching_brother].character==current){
        when_to_break=false;
        have_found=true;
        index_of_current_node=current_searching_brother;
    }else{
        if(tree[current_searching_brother].next_brother!=-1){
            current_searching_brother=tree[current_searching_brother].next_brother;
        }else{
            when_to_break=false;
            have_found=false;
        }
    }
}
when_to_break=true;
if(!have_found){
    adding_node={current,-1,-1};
    tree [added_limit]=adding_node;
    tree[current_searching_brother].next_brother=added_limit;
    index_of_current_node=added_limit;
    added_limit++;
}
}
}
}

bool is_there_string(string searched_string){
char current;
int index_of_current_node=0,current_searching_brother;
bool when_to_break=true;
for(int counter=0;counter<searched_string.size();counter++){
    current=searched_string.at(counter);
    if(tree[index_of_current_node].son==-1){
        return false;
    }else{
    current_searching_brother=tree[index_of_current_node].son;
    while(when_to_break){
        if(tree[current_searching_brother].character==current){
        when_to_break=false;
        index_of_current_node=current_searching_brother;
        }else{
        if(tree[current_searching_brother].next_brother!=-1){
            current_searching_brother=tree[current_searching_brother].next_brother;
        }else{
            return false;
        }
        }
    }
    when_to_break=true;
    }
}
return true;
}

int main(){
initialise_node_tree();
int number_addings,number_of_searchs;
cin>>number_addings;
string adding_string;
for(int counter=0;counter<number_addings;counter++){
    cin>>adding_string;
    add_string(adding_string);
//    for(int counter=0;counter<added_limit;counter++){
//    cout<<counter<<" "<<tree[counter].character<<" "<<tree[counter].son<<" "<<tree[counter].next_brother<<endl;
//}
//cout<<endl;
}
cin>>number_of_searchs;
string searched_string;
for(int counter=0;counter<number_addings;counter++){
    cin>>searched_string;
    cout<<is_there_string(searched_string)<<endl;
}
return 0;
}
