#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    int data;
    Node *prev;
    Node *next;
};
class doubly:public Node
{
    public:
        Node *head,*last;
        doubly()
        {
            head=NULL;
            last=NULL;
        }
        void Insert(double item);
        void display();
        void display_reverse();
        void sum();
        void average();
        void maximum();
        void frequency();

};
void doubly::Insert(double item)
{
    Node *NewNode=new Node();
    NewNode->data=item;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    if(head==NULL)
    {
        head=NewNode;
        last=NewNode;

    }
    else
    {
        last->next=NewNode;
        NewNode->prev=last;
        last=last->next;
    }
}
void doubly::display()
{
    Node *dhead;
    dhead=head;
    while(dhead!=NULL)
    {
        cout<<dhead->data<<"<->";
        dhead=dhead->next;
    }
}
void doubly::display_reverse()
{
    Node *tmp=new Node;
    while(last!=NULL)
    {
        cout<<last->data<<"<->";
        last=last->prev;
    }
    cout<<endl;
}

void doubly::sum()
{
    Node *dhead=new Node;
    dhead=head;
    double total=0;
    while(dhead!=NULL)
    {
        total+=dhead->data;
        dhead=dhead->next;
    }
    cout<<"sum of list="<<total<<endl;

}
void doubly::average()
{
    Node *dhead=new Node;
    dhead=head;
    double total=0;
    int start=0;
    while(dhead!=NULL)
    {
        total+=dhead->data;
        dhead=dhead->next;
        start++;
    }
    cout<<"no of node:"<<start<<endl;
    cout<<"average="<<total/start<<endl;
}

void doubly::maximum()
{
    Node *dhead=new Node;
    dhead=head;
    double max;
    max=dhead->data;
    dhead=dhead->next;
    while(dhead!=NULL)
    {
        if(dhead->data>max)
        {
            max=dhead->data;
        }
        dhead=dhead->next;
    }
    cout<<"Maximum vaule is:"<<max<<endl;
}
void doubly::frequency()
{
    Node *dhead=new Node;
    int start=0;
    dhead=head;
    double item;
    cout<<"enter the item for frequency:";
    cin>>item;
    while(dhead!=NULL)
    {
        if(dhead->data==item)
        {
            start++;
        }
        dhead=dhead->next;

    }
    cout<<"frequency of "<<item<<" is "<<start<<endl;
}

int main()
{
    doubly ob;
    ob.Insert(10);
    ob.Insert(100);
    ob.Insert(55);
    ob.Insert(678);
    ob.Insert(15);
    ob.Insert(60);
    ob.Insert(55);
    ob.Insert(60);

    ob.display();
    cout<<endl<<"reverse implement:"<<endl;
    ob.display_reverse();
    ob.sum();
    ob.average();
    ob.maximum();
    ob.frequency();



    return 0;
}
