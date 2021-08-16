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
Node* search(Node* root, int key){
    if(root == NULL)
        return NULL;

    if(root->data == key)
        return root;
    
    if(root->data > key)
        return search(root->left, key);

    return search(root->right, key);
}
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL)
        curr = curr->left;
    
    return curr;
}
Node* deleteBST(Node* root, int key){
    
    if(key < root->data)
        root->left = deleteBST(root->left, key);

    else if(key > root->data)
        root->right  = deleteBST(root->right, key);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
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
    cout<<endl;
    // if(search(root, 5) == NULL)
    //     cout<<"Node dosent exists";
    // else
    //     cout<<"Node exists";
    root = deleteBST(root, 5);
    inorder(root);
   return 0;
}


