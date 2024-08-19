#include <iostream>
using namespace std;
class Poly
{
    int i,size,size2,limit,a[10],b[10],sum[10];
    public:
    void accept();
    void display();
    void add();
};

void Poly::accept()
{
    cout<<"Enter total terms for 1st and 2nd polynomial: ";
    cin>>size>>size2;
    if(size >= size2)
     limit = size;
    else
     limit = size2;
    for(i=size-1;i>=0;i--)
    {
        cout<<"Enter term for first having "<<i<<"th exponent: ";
        cin>>a[i];
    }
    cout<<"\n----------------------------------------------------\n";
    for(i=size2-1;i>=0;i--)
    {
        cout<<"Enter term for second having "<<i<<"th exponent: ";
        cin>>b[i];
    }
}


void Poly::add()
{
   for(i=0;i<limit;i++)
    sum[i] = a[i] + b[i];
}

void Poly::display()
{
    cout<<"Polynomial sum: "<<endl;
    for(i=limit-1;i>=0;i--)
    {
        if(i == 0&&sum[i] != 0)
         cout<<sum[i];
        else
        {
            if(sum[i] != 0)
             cout<<sum[i]<<"x";
            if(i!=1)
             cout<<"^"<<i;
            if(sum[i-1]!=0)
             cout<<" + ";
        }
    }
}

int main()
{
    Poly obj;
    obj.accept();
    obj.add();
    obj.display();
    return 0;
}
