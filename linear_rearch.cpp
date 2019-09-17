#include<bits/stdc++.h>
using namespace std;

int  Linear_search(int arr[],int size,int item)
{
    //cout<<"ok";

    for(int i=0;i<size;i++)
    {
        if(item==arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int arr[100];
    int n;
    int R;
    cout<<"enter the range of array:";
    cin>>n;
    ifstream myfile;
    myfile.open("data.txt");
    for(int i=0;i<n;i++)
    {
        myfile>>arr[i];
    }
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    myfile.close();
    int k;
    cout<<"enter the item:";
    cin>>k;

   R= Linear_search(arr,n,k);
   if(R==-1)
   {
       cout<<"not found"<<endl;
   }
   else
   {
       cout<<k<<" is found at index "<<R;
   }
    return 0;
}
