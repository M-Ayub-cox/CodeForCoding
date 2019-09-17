#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;
    Node *tmp;
};

//For creating a new BST node

Node *create_newNode(int item){
    Node *new_node = new Node();
    new_node->key = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inorder(Node *root){
    if (root != NULL){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
/*
void preorder(Node *root){
    if (root != NULL){
        cout<<root->key<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<endl;
    }
}
*/

Node *insert(Node *node, int key){
    if (node == NULL) return create_newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
void tree_minimum(Node *root)
{
    //Node *tmp=new Node();
    //tmp=root;
    //tmp->key=root->key;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    cout<<"minimun value="<<root->key<<endl;
}
void tree_maximum(Node *root)
{
    Node *tmp=new Node();
    tmp=root;
    while(tmp->right!=NULL)
    {
        tmp=tmp->right;
    }
    cout<<"maximun value="<<tmp->key<<endl;
}
int main()
{

    /*         50
            /      \
           30       70
          /  \     /  \
        20   40   60   80
    */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    tree_minimum(root);
    tree_maximum(root);
/*
    cout<<endl;

    preorder(root);

    cout<<endl;

    postorder(root);
*/
    return 0;
}
