#include <iostream>
void menu(Stack_class &);
using namespace std;
class Stack_class
{
 int stack[12]; //Stack
 int tos,size; //Variables: TOS(stack pointer) , i(counter) , size(Size of stack)
 public:
 void accept();
 void push();
 void pop();
 void display();
};


//Accept function definition: Class- Stack_class
void Stack_class::accept()
{
 cout<<"Enter the size of the stack(Max-12): ";
 cin>>size;
 tos = -1;
}


//Push function definition: Class- Stack_class
void Stack_class::push()
{
 char confirm; //Variables: confirm(To confirm to do push operation)
 while(1)
 {
    tos++;
    if(tos >= 12)
    {
     cout<<"Stack overflow";
     break;
    }
    else
    {
     cout<<"Enter the element here: ";
     cin>>stack[tos];
     cout<<"Do you want push again(y/n): ";
     cin>>confirm;
     if(confirm != 'y' || confirm != 'Y')
      break;
    }
 }
 cout<<"Pushing completed";
}


//Pop function definition: Class- Stack_class
void Stack_class::pop()
{
 char confirm; //Variables: confirm(To confirm to do push operation)
 while(1)
 {
    if(tos < 0)
    {
     cout<<"Stack underflow";
     break;
    }
    else
    {
     stack[tos] = 0;
     tos--;
     cout<<"Do you want pop again(y/n): ";
     cin>>confirm;
     if(confirm != 'y' || confirm != 'Y')
      break;
    }
 }
 cout<<"Poping completed";
}


//Display function definition: Class- Stack_class
void Stack_class::display()
{
 int i;
 for(i=0;i<=tos;i++)
  cout<<stack[tos]<<endl;
}


//Main function
int main()
{
  Stack_class obj;
  char confirm;
  obj.accept();
  do
  {
    menu(obj);
    cout<<"Do you want to perform operation again(y/n): ";
    cin>>confirm;
  }while(confirm=='y'||confirm=='Y');     
  return 0;
}


//Menu function Definition
void menu(Stack_class &obj)
{
  int option;

  cout<<"---------------------------------Main Menu---------------------------------\n";
  cout<<"1.)Perform push operation\n2.)Perform pop operation\n3.)Display elements\n";
  cout<<"Input the option: ";
  cin>>option;
  switch(option)
  {
   case 1: obj.push();
           break;
   case 2: obj.pop();
           break;
   case 3: obj.display();
            break;
   default: cout<<"Aborting operation......"
  }
}
   
