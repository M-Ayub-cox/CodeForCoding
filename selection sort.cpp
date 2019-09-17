#include<bits/stdc++.h>
using namespace std;

void showlist(double *arr,int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
void selection_sort(double *arr,int n)
{
    int  i_min;
    for(int i=0;i<n-1;i++)
    {
        i_min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i_min])
            {
                i_min=j;
            }

        }
         swap(arr[i_min],arr[i]);
    }
}

int main()
{
    int n;
    cout<<"enter the value of range:";
    cin>>n;
    double arr[n];
    ifstream mfile;
    mfile.open("value.txt");
    for(int i=0;i<n;i++)
    {
        mfile>>arr[i];
    }
    cout<<endl<<"before sorting:";
    showlist(arr,n);
    selection_sort(arr,n);
    cout<<"after sorting:"<<endl;
    showlist(arr,n);

    return 0;

}
