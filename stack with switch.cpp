#include<bits/stdc++.h>
using namespace std;
int maxstk=10,Top=-1;
class Node
{
public:

    int data;
    Node *link;

};
class linkedList:public Node
{
 public:

    Node *head,*top;
    linkedList()
    {
        head=NULL;
        top=NULL;
    }
    void poush(double item);
    void pop();
    void searchh();
    void display();

};

void linkedList::poush(double item)
{
 if(Top==maxstk)
 {
     cout<<"overflow"<<endl;
     return;
 }
 else
 {
      Top++;
      cout<<"top="<<Top<<endl;
     Node *New=new Node;
     New->data=item;
     New->link=NULL;
     if(head==NULL)
     {
      head=New;
      top=New;
     }
    else
     {
      top->link=New;
      top=top->link;
     }
  }
}
void linkedList::display()
{
    Node *tmp=new Node;
    tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->link;
    }
}
void linkedList::pop()
{
    if(Top<0)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        Node *dhead,*pre;
       dhead=head;
       while(dhead->link!=NULL)
       {
        pre=dhead;
        dhead=dhead->link;
       }
       cout<<endl<<dhead->data<<"is deleted"<<endl;
      pre->link=NULL;
      Top--;
    }
}
void linkedList::searchh()
{
    Node *dhead,*tmp;
    double value;
    cout<<"enter the searching item:"<<endl;
    cin>>value;
    dhead=head;
   int  start=0;
    while(dhead->data!=value)
    {
        start++;
        dhead=dhead->link;
    }
    if(dhead->data==value)
    {
        cout<<"item is found and position is: "<<start<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
}
int main()
{
    linkedList Stack;
    int c;
    double item;
    while(1)
    {
        cout<<"poush:1   pop:2   search:3   display:4   exit:5  "<<endl;
        cout<<"enter your choice:";
        cin>>c;
        switch(c)
        {
     case 1:
          cout<<"Enter the item:";
          cin>>item;
          Stack.poush(item);
          break;
     case 2:
         Stack.pop();
         break;
     case 3:
        Stack.searchh();
        break;
     case 4:
        Stack.display();
        break;
     case 5:
        return 0;
     default:
        cout<<"wrong input:";
        break;


        }
    }
}
