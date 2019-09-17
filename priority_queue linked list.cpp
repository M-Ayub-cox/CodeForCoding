#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    int prio;
    Node  *link;
};

class dataStructure:public Node
{
public:
    Node *head;
    dataStructure()
    {
        head=NULL;
    }
    void Enqueue();
    void dequeue();
    void showlist();
};
void dataStructure::Enqueue()
{
    Node *NewNode=new Node();
    double item,priority;
    cout<<"Enter the value of Item & priority:";
    cin>>item>>priority;
    NewNode->data=item;
    NewNode->prio=priority;
    NewNode->link=NULL;
    Node *tmp;
    tmp=head;
    if(head==NULL || priority<head->prio)
    {
        NewNode->link=head;
        head=NewNode;

    }
    else
    {
        while(tmp->link!=NULL && tmp->link->prio<=priority)
        {

            tmp=tmp->link;
        }
        NewNode->link=tmp->link;
        tmp->link=NewNode;

    }

}
void dataStructure::dequeue()
{
   if(head==NULL)
   {
       cout<<"underflow"<<endl;
       return ;
   }
   else
   {
       cout<<"deleted value is "<<head->data<<endl;
       head=head->link;
   }
}
void dataStructure::showlist()
{
    if(head==NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }
    Node *dhead=new Node();
    dhead=head;
    while(dhead!=NULL)
    {
        cout<<dhead->data<<"\t"<<dhead->prio<<endl;
        dhead=dhead->link;
    }
}
int main()
{
    dataStructure Priority;
    int c;
    do
    {
        cout<<"Enqueue:1  Dequeue:2  display:3 Exit:4"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            Priority.Enqueue();
            break;
        case 2:
            Priority.dequeue();
            break;
        case 3:
            Priority.showlist();
            break;
        case 4:
            cout<<"Exit";
            break;
        default:
            cout<<"wrong input";
            break;
        }
    }while(c!=4);
}
