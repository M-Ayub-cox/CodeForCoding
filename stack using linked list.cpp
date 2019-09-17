#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *link;
};
class linkedList:public node
{
public:
    node *head,*top;
    linkedList()
    {
        head=NULL;
        top=NULL;
    }
  void push1(double item);
  void display();

};
void linkedList::push1(double item)
{

    node *NewNode=new node();
    NewNode->data=item;
    NewNode->link=top;
    top=NewNode;
    /*if(head==NULL)
    {
        head=NewNode;
        top=NewNode;
    }
    else
    {

      top->link=NewNode;
      top=top->link;

    }
   */
}
void linkedList::display()
{
    node *tmp=new node;

  // check for stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        tmp = top;
        while (tmp != NULL) {

            // print node data
            cout <<  tmp->data << " ";

            // assign temp link to temp
            tmp = tmp->link;
        }
}
}
int main()
{
    linkedList Stack;
    Stack.push1(10);
    Stack.push1(15);
    Stack.push1(30);
    Stack.push1(5);
    Stack.push1(1);
    Stack.push1(11);

    Stack.display();
}
