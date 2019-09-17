#include<bits/stdc++.h>
using namespace std;

double Queue[10];
int maxm=9,Front=-1,rear=-1;

void insertt(double item)
{
    if(rear==maxm)
    {
        cout<<"overflow"<<endl;
        return ;
    }
    else
    {
        if(Front==-1)
        {
            Front=0;
        }
        rear++;
        Queue[rear]=item;
    }


}

void Delete()
{
    if(Front==-1 ||Front>rear)
    {
        cout<<"underflow"<<endl;
    }
    else
    {
        cout<<"The element "<<Queue[Front]<<" is deleted"<<endl;
        Front++;
    }
}
void show()
{
    if(Front==-1)
        cout<<"no element"<<endl;
    else
    {
        cout<<"queue elements are:";
        for(int i=Front;i<=rear;i++)
        {
            cout<<Queue[i]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout<<"enqueue:1   dequeue:2  display:3  exit:4"<<endl;
        cout<<"enter your choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
            double item;
            cout<<"enter your item:";
            cin>>item;
            insertt(item);
            break;
        case 2:
            Delete();
            break;
        case 3:
            show();
            break;
        case 4:

            cout<<"exit"<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
          break;



        }

    }while(choice!=4);

}

