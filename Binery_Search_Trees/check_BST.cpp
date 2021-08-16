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
bool checkBST(Node* root, Node* min, Node* max){
    if(root == NULL)
        return true;

    if(min != NULL && root->data <= min->data)
        return false;
    if(max != NULL && root->data >= max->data)
        return false;

    bool leftV = checkBST(root->left, min, root);
    bool rightV = checkBST(root->right, root, max);
    return leftV and rightV;
}
int main()
{
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(8);
    cout<<checkBST(root, NULL, NULL);
   return 0;
}