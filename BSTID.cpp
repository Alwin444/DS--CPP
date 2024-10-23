#include <iostream>
using namespace std;


struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};
typedef struct NODE tree;


class Alwin
{
   tree *root;
   int num;
   char choice;
   public:
   Alwin()
   {root = nullptr;}
   void input();//Main function call , last defined
   tree *insert(tree *root,int num); //Main Algorithm , 1st defined
   void display(tree *root); //2nd defined
   tree *deletion(tree *root,int num); //Main Algorithm to delete
   tree *min(tree *root);
   void dinp();
};


tree *Alwin::insert(tree *root,int num)
{
    if(root == nullptr)
    {
        root = new tree;
        root->left = nullptr;
        root->right = nullptr;
        root->data = num;
    }
    else if(root->data < num)
     root->right = insert(root->right,num);
    else if(root->data > num)
     root->left = insert(root->left,num);
    else
    {
        if(root->data == num)
         cout<<"Duplicate value, Enter again\n";
    }
    return root;
}


void Alwin::display(tree *root)
{
    if(root != nullptr)
    {
        display(root->left);
        cout<<root->data<<'\t';
        display(root->right);
    }
}


void Alwin::input()
{
   do
   {
       cout<<"Enter the number: ";
       cin>>num;
       root = insert(root,num);
       cout<<"Do you want to perform again(y/n): ";
       cin>>choice;
   }while(choice == 'y' || choice == 'Y');
   cout<<"\nElements are: \n";
   display(root);
}


tree *Alwin::deletion(tree *root,int num)
{
    if(root == nullptr)
    {
        cout<<"Invalid element";
        return root;
    }
    else if(num > root->data)
     root->right = deletion(root->right,num);
    else if(num < root->data)
     root->left = deletion(root->left,num);
    else
    {
        if(root->right == nullptr)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == nullptr)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }
        
        tree *temp = min(root->right);
        root->data = temp->data;
        root->right = deletion(root->right,num);
    }
    return root;
}


tree *Alwin::min(tree *root)
{
    tree *temp = root;
    while(temp && temp->left != nullptr)
     temp = temp->left;
    return temp;
}

void Alwin::dinp()
{
    char choice;
    int dt;
    do
    {
        cout<<"\n\nEnter the element to delete: ";
        cin>>dt;
        root = deletion(root,dt);
        cout<<"\nDo you want to delete again(y/n): ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    cout<<"\nElements are:\n";
    display(root);
}


int main()
{
   Alwin obj;
   obj.input();
   obj.dinp();
   return 0;
}
