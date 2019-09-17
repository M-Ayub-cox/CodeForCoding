#include<bits/stdc++.h>
using namespace std;

class node
{
public:

    int data;
    node *link;
};
class operation:public node
{
public:
    node *head,*tail;
    operation()
    {
        head=NULL;
        tail=NULL;
    }
   void insert(int item);

   void printlist();
   void insert_atFirst(int item);
   void insert_atANY(int position,int item);
   void insert_atLast(int item);
   void delete_atFirst();
   void delete_atLast();
   void delete_atANY(int position);
};
void operation::insert(int item)
{

    node *NewNode=new node();
    NewNode->data=item;
    NewNode->link=NULL;
    if(head==NULL)
    {
        head=NewNode;
        tail=NewNode;
    }
    else
    {
      tail->link=NewNode;
      tail=tail->link;
    }

}

void operation::printlist()
{
    node *tmp=new node;
    tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->link;
    }
}

void operation::insert_atFirst(int item)
{
    node *NewNode=new node;
    NewNode->data=item;
    NewNode->link=head;
    head=NewNode;
}

void operation::insert_atANY(int position,int item)
{
    node *previous,*current,*dhead;
    node *New=new node();
    dhead=head;
    int start=1;
    while(position>start)
    {
        previous=dhead;
        current=dhead->link;
        dhead=dhead->link;
        start++;
    }
    New->data=item;
    New->link=current;
    previous->link=New;
}/// end insert any place

void operation::insert_atLast(int item)
{
    node *NewNode= new node;
    node *dhead;
    dhead=head;
    while(dhead->link!=NULL)
    {
        dhead=dhead->link;
    }
    NewNode->data=item;
    NewNode->link=NULL;
    dhead->link=NewNode;

}

void operation::delete_atFirst()
{
    head=head->link;
}

void operation::delete_atLast()
{
 node *dhead,*preNode;
 dhead=head;
 while(dhead->link!=NULL)
 {
     preNode=dhead;
     dhead=dhead->link;
 }
 preNode->link=NULL;
}

void operation::delete_atANY(int position)
{
    node *prenode,*dhead,*current;
    dhead=head;
    int start=1;
    while(start<position)
    {
        prenode=dhead;
        current=dhead->link;
        dhead=dhead->link;
        start++;
    }
    prenode->link=current->link;

}

int main()
{
    operation ob;
    double item;
    int p,dp;
    cout<<"enter the value of node:";
    cin>>item;
    while(item!='\0')
    {
        ob.insert(item);
        cin>>item;
    }

    cout<<"Original Link listed:";
    ob.printlist();

    cout<<endl<<"Insert a node of 10 at first"<<endl;
   ///cout<<"Enter the value of that position:";
   // cin>>item;
    ob.insert_atFirst(10);
    //cout<<endl<<"After insert at first:"<<endl;
    ob.printlist();


    cout<<endl<<"insert a node of 15 at any place "<<endl;

    cout<<endl<<"enter the position:";
   //cin>>p;
    ob.insert_atANY(3,15);
    //cout<<endl<<"After insert A node at any place:"<<endl;
    ob.printlist();

    cout<<endl<<"insert a node of 25 at last "<<endl;
    ob.insert_atLast(25);
    //cout<<endl<<"After insert A node at Last"<<endl;
    ob.printlist();

    cout<<endl<<"Delete at first"<<endl;
    ob.delete_atFirst();
    ob.printlist();

     cout<<endl<<"Delete at Last"<<endl;
    ob.delete_atLast();
    ob.printlist();


    cout<<endl<<"Delete from any place"<<endl;
    cout<<"Enter the deleting position:";

    //cin>>dp;
    ob.delete_atANY(2);
    ob.printlist();



    return 0;
}
