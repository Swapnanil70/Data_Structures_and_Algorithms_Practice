#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* sortedArrayToBST(int arr[], int start, int end){
    if(start > end)
        return NULL;

    int mid =  (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
    return root;
}
void inorder(Node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int arr[] = {1, 3, 5, 6, 8, 10 , 50 , 70,};
    Node* root = sortedArrayToBST(arr, 0, 7);
    inorder(root);
   return 0;
}