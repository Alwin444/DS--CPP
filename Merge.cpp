#include <iostream>
using namespace std;


class M{
    int a[10],b[10],c[23],i,j,index,s1,s2;
    public:
    void accept();
    void merge();
    void display();
};


void M::accept(){
    cout<<"Enter the size of the array 1 and array 2: ";
    cin>>s1>>s2;
    for(i=0;i<s1;i++){
        cout<<"Enter here for array 1: ";
        cin>>a[i];
    }
    cout<<'\n';
    for(i=0;i<s2;i++){
        cout<<"Enter here for array 2: ";
        cin>>b[i];
    }
}


void M::merge(){
    i = j = index = 0;
    while(i < s1 && j < s2){
        if(a[i] <= b[j]){
            c[index] = a[i];
            index++;
            i++;
        }
        
        else{
            c[index] = b[j];
            index++;
            j++;
        }
    }

    while(i<s1){
        c[index] = a[i];
        index++;
        i++;
    }
    while(j<s2){
        c[index] = b[j];
        index++;
        j++;
    }
}


void M::display(){
    index = s1+s2;
    cout<<"Merged arrays: ";
    for(i=0;i<index;i++)
     cout<<c[i]<<'\t';
}


int main(){
    M obj;
    obj.accept();
    obj.merge();
    obj.display();
    return 0;
}
