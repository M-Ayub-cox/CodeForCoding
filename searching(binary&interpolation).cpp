#include<bits/stdc++.h>
using namespace std;

/*void bsort(int arry[],int r)
{
    int tmp;
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<r-i;j++)
        {
            if(arry[j]>arry[j+1])
            {
               tmp=arry[j];
               arry[j]=arry[j+1];
               arry[j+1]=tmp;
            }
        }
    }

}*/

void binary_search(int arry[],int r,int item)
{
    //cout<<"binary"<<endl;
    int l=0;int h=r-1;int mid;
    mid=(h+l)/2;
   // cout<<"mid ="<<mid<<endl;
    int i=1;
    while(arry[mid]!=item)
    {
     //cout<<"in loop"<<endl;
       if(item<arry[mid])
       {
           l=l;
           h=mid-1;
       }
       else
       {
           l=mid+1;
           h=h;
       }
       i++;
       mid=l+(h-l)/2;
    }
    cout<<"Index of item="<<mid<<endl;
    cout<<"Iteration="<<i<<endl;
}

void interpolation_search(int arry[],int r,int item)
{
   int ll=0;int hh=r-1;int mid;
    mid=ll+(hh-ll)*(item-arry[ll])/(arry[hh]-arry[ll]);
    ///cout<<"hh-ll="<<hh-ll<<"  "<<"arry[hh]-arry[ll]="<<arry[hh]-arry[ll]<<"  "<<"item-array[ll]="<<item-arry[ll]<<endl;
   ///cout<<"mid ="<<mid<<endl;
    int i=1;
    while(arry[mid]!=item)
    {
     //cout<<"in loop"<<endl;
       if(item<arry[mid])
       {
           ll=ll;
           hh=mid-1;
       }
       else
       {
           ll=mid+1;
           hh=hh;
       }
       i++;
    mid=ll+((hh-ll)/(arry[hh]-arry[ll]))*(item-arry[ll]);
    }
    cout<<"Index of item="<<mid<<endl;
    cout<<"Iteration="<<i<<endl;
}


int main()
{
    int arry[100];
     cout<<"enter the value of array size:";
    int r;
    cin>>r;
    ifstream myfile;
    myfile.open("data.txt");

    for(int i=0;i<r;i++)
    {
        myfile>>arry[i];
    }

    sort(arry,arry+r);

    for(int i=0;i<r;i++)
    {
        cout<<arry[i]<<" ";
    }
    cout<<endl<<"enter the value of Item"<<endl;
    int item;
    cin>>item;
    int b;
    while(1)
    {
          cout<<endl<<"ENTER:    1 For binary   2 for Interpolation    '3 for exit'"<<endl;
          int b;
          cin>>b;
          if(b==1)
          {
              binary_search(arry,r,item);
          }
          else if(b==2)
          {
              interpolation_search(arry,r,item);
          }
          else
          {
              return 0;
          }
    }
    return 0;
}
