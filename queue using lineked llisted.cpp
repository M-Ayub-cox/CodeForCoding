#include<bits/stdc++.h>
using namespace std;
int top=-1,maxtk=4;
class node
{
public:
    int data;
    node *link;

};
class structure:public node
{
    node *head,*last;
public:
    structure()
    {
        head=NULL;
        last=NULL;
    }
    void enqueue();
    void dequeue();
    void showlist();
};
void structure:: enqueue()
{
    if(top==maxtk)
    {
        cout<<"overflow"<<endl;
        return ;
    }
    else
    {
        top++;
        double item;
        cout<<"enter the item:";
        cin>>item;
        node *NewNode=new node;

        NewNode->data=item;
        NewNode->link=NULL;
        if(head==NULL)
        {
            head=NewNode;
            last=NewNode;
        }
        else
        {
            last->link=NewNode;
            NewNode->link=NULL;
        }


    }

}
void structure:: dequeue()
{
    if(top==-1)
    {
        cout<<"underflow"<<endl;
        return ;
    }
    else
    {
        node *dhead,*current;
        dhead=head;
        while(dhead->link!=NULL)
        {
            current=head;
            dhead=dhead->link;
        }
        current->link=NULL;
        top--;

    }
}
void structure:: showlist()
{
    if(top==-1)
    {
        cout<<"empty list"<<endl;
    }
    else
    {
        node *dhead=new node();
    dhead=head;
       while(dhead!=NULL)
      {
        cout<<dhead->data<<"-";
        dhead=dhead->link;
      }
    }
}
int main()
{
  structure ob;
    int choice;
    do
    {
        cout<<"enqueue:1   dequeue:2  display:3  exit:4"<<endl;
        cout<<"enter your choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
           // double item;

           ob.enqueue();
            break;
        case 2:
            ob.dequeue();
            break;
        case 3:
            ob.showlist();
            break;
        case 4:

            cout<<"exit"<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
          break;



        }

    }while(choice!=4);
   return 0;
}

