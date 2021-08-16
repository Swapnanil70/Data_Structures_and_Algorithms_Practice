#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lH = height(root->left);
    int rH = height(root->right);
    return max(lH, rH) + 1;
}
int calcHeight(Node* root){
    if(root == NULL)
        return 0;

    return max(calcHeight(root->left) , calcHeight(root->right)) + 1;
}
int calcDiameter(Node* root){
    if(root == NULL)
        return 0;
    int lH = calcHeight(root->left);
    int rH = calcHeight(root->right);
    int currDiameter = lH + rH + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}
// optimized approach to calculate the diameter
int calDiameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lD = calDiameter(root->left, &lh);
    int rD = calDiameter(root->right, &rh);

    int currD = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currD, max(lD, rD)); 
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<height(root)<<endl;
    cout<<calcDiameter(root)<<endl;
    int height = 0;
    cout<<calDiameter(root, &height);
   return 0;
}