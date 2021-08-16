#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node *root, int val){
    if(root ==  NULL)
        return new Node(val);
    if(val < root->data)
        root->left = insertBST(root->left, val);
    
    else
        root->right = insertBST(root->right, val);

    return root;
}
void inorder(Node *root){
    if(root  == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root = NULL;
    root = insertBST(root,10);
    for(int i = 2; i < 7; i++)
        insertBST(root, i);
    insertBST(root, 15);
    insertBST(root, 12);
    inorder(root);
   return 0;
}


