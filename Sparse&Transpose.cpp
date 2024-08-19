#include <iostream>
using namespace std;
class Sparse
{
  int ar[10][10],spars[10][3],i,j,row,col,value_count,k;
  public:
  void accept();
  void display();
  void transpose();
  void sparser();
};

void Sparse::accept()
{
    value_count = 0;
    cout<<"Enter the row and column: ";
    cin>>row>>col;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<"Enter here: ";
            cin>>ar[i][j];
            if(ar[i][j] != 0)
             value_count++;
        }
    }
}

void Sparse::sparser()
{
    k = 0;
    spars[k][0] = row;
    spars[k][1] = col;
    spars[k][2] = value_count;
    k++;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(ar[i][j] != 0)
            {
                spars[k][0] = i;
                spars[k][1] = j;
                spars[k][2] = ar[i][j];
                k++;
            }
        }
    }
}


void Sparse::transpose()
{
    int trans[value_count+1][3],index = 0;
    trans[0][0] = spars[0][1];
    trans[0][1] = spars[0][0];
    trans[0][2] = spars[0][2];
    index++;
    for(i=0;i<col;i++)
    {
        for(j=1;j<=value_count;j++)
        {
            if(spars[j][1]==i)
            {
                trans[index][0] = spars[j][1];
                trans[index][1] = spars[j][0];
                trans[index][2] = spars[j][2];
                index++;
            }
        }
    }
    cout<<"\n\n---------Transpose---------\n\n";
    for(i=0;i<=value_count;i++)
    {
        for(j=0;j<3;j++)
         cout<<trans[i][j]<<'\t';
        cout<<"\n";
    }
}


void Sparse::display()
{
    cout<<"\n----------Triplet Representation----------\n";
    for(i=0;i<=value_count;i++)
    {
        for(j=0;j<3;j++)
         cout<<spars[i][j]<<'\t';
        cout<<'\n';
    }
}


int main()
{
    Sparse obj;
    char confirm;
    obj.accept();
    obj.sparser();
    obj.display();
    cout<<"\nDo you need to perform transpose operation(y/n): ";
    cin>>confirm;
    if(confirm == 'y')
     obj.transpose();
    return 0;
}
