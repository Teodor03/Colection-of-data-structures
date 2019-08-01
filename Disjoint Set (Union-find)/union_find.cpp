#include<iostream>
using namespace std;

struct dsu_object{
int parent;
int depth;
};

const int Max_Number_of_Objects=1001;

dsu_object dsu_objects [Max_Number_of_Objects];

void dsu_initialise(int n){
    for(int counter=0;counter<n;counter++){
        dsu_objects[counter].depth=0;
        dsu_objects[counter].parent=counter;
    }
}

int dsu_find(int searched){
if(searched!=dsu_objects[searched].parent){
    dsu_objects[searched].parent=dsu_find(dsu_objects[searched].parent);
}
return dsu_objects[searched].parent;
}

void dsu_union(int first,int second){
int first_parent,second_parent;
first_parent=dsu_find(first);
second_parent=dsu_find(second);
if(first_parent==second_parent){
    return;
}
if(dsu_objects[first_parent].depth>dsu_objects[second_parent].depth){
    dsu_objects[second_parent].parent=first_parent;
    return;
}
if(dsu_objects[first_parent].depth<dsu_objects[second_parent].depth){
    dsu_objects[first_parent].parent=second_parent;
    return;
}
dsu_objects[second_parent].parent=first_parent;
dsu_objects[first_parent].depth++;
return;
}
//driver program so you can check how it works
int main(){
int type,a,b,number_of_objects,f_first,f_second;
cin>>number_of_objects;
dsu_initialise(number_of_objects);
while(true){
    cin>>type;
    //0 for union groups of 2 objects, 1 to ask if 2 objects are from same group
    if(type==0){
    cin>>a>>b;
    a--;
    b--;
    dsu_union(a,b);
    }else{
    cin>>a>>b;
    a--;
    b--;
    f_first=dsu_find(a);
    f_second=dsu_find(b);
    if(f_first==f_second){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    }
}
return 0;
}
