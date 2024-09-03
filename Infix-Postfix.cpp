//Under research

/*
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
int prec(char i);
int main()
{
    char stack[20],ar[20],po[20];
    int i,po_count = -1,tos = -1,size;
    cout<<"Expression can have operators [+,-,*,/,^,(,)]: ";
    cout<<"Enter the length of expression (Max -17): ";
    cin>>size;
    ar[0] = '(';
    cout<<"Enter the expression: ";
    for(i=1;i<=size;i++)
     cin>>ar[i];
    ar[size+1] = ')';
    for(i=0;i<=size+1;i++)
    {
        if(isdigit(ar[i]))
         po[++po_count] = ar[i];
        else
        {
            if(ar[i] == '(')
             stack[++tos] = ar[i];
            else if(ar[i] == ')')
            {
                while(stack[tos] != '(')
                 po[++po_count] = stack[tos--];
                tos--;
            }
            else
            {
                if(prec(ar[i]) < prec(stack[tos]))
                {
                    po[++po_count] = stack[tos];
                    stack[tos] = ar[i];
                }
                else
                 stack[++tos] = ar[i];
            }
        }
    }
    
    for(i=0;i<size;i++)
     cout<<po[i]<<"\t\t";
    return 0;
}

int prec(char i)
{
    switch(i)
    {
        case '^': return 5;
        case '/': return 4;
        case '*': return 3;
        case '+': 
        case '-': return 2;
        default: return -1;
    }
}

*/
