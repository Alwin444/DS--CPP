#include <iostream>
using namespace std;


int count = 0;
struct Node
{
    int data;
    struct Node *ptr;
};
typedef struct Node node;


class Swaper
{
    node *fix1,*fix2,*pre1,*pre2,*temp,*list,*first,*current;
    int pos1,pos2;
    public:
    void input();
    void swap();
    void display();
};


void Swaper::input()
{
    first = nullptr;
    char choice;
    do
    {
        count++;
        list = new node;
        cout<<"here: ";
        cin>>list->data;
        list->ptr = nullptr;
        if(first == nullptr)
         first = current = list;
        else
        {
            current->ptr = list;
            current = current->ptr;
        }
        cout<<"Continue?: ";
        cin>>choice;
    }while(choice == 'y');
}

void Swaper::swap()
{
    char choice;
    int dup_count;
    do
    {
        pre1 = pre2 = nullptr;
        fix1 = fix2 = first;
        if(count < 2)
         cout<<"No nodes";
        else
        {
            dup_count = 1;
            cout<<"Postion: ";
            cin>>pos1>>pos2;
            if(pos1 < 1 || pos2 > count)
            {
                do
                {
                    cout<<"Invalid positons: ";
                    cin>>pos1>>pos2;
                }while(pos1 < 1 || pos2 > count);
            }
            while(dup_count < pos1)
            {
                pre1 = fix1;
                fix1 = fix1->ptr;
                dup_count++;
            }
            dup_count = 1;
            while(dup_count < pos2)
            {
                pre2 = fix2;
                fix2 = fix2->ptr;
                dup_count++;
            }
        
        
            //Adjacent nodes
            if(fix1->ptr == fix2)
            {
             if (pre1 != nullptr)
              pre1->ptr = fix2;
             else
              first = fix2;
             fix1->ptr = fix2->ptr;
             fix2->ptr = fix1;
            }
            //Non Adjacent nodes
            else 
            {
             if (pre1 != nullptr)
              pre1->ptr = fix2;
             else
              first = fix2;
             if (pre2 != nullptr)
              pre2->ptr = fix1;
             temp = fix1->ptr;
             fix1->ptr = fix2->ptr;
             fix2->ptr = temp;
            }
        }
        cout<<"Again: ";
        cin>>choice;
    }while(choice == 'y');
}


void Swaper::display()
{
    current = first;
    while(current != nullptr)
    {
        cout<<current->data<<'\t';
        current = current->ptr;
    }
}


int main()
{
    Swaper obj;
    obj.input();
    obj.swap();
    obj.display();
    return 0;
}
