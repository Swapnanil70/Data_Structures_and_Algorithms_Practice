#include<iostream>
#include<stack>
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
void zigzagTraversal(Node* root){
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool lefttoRight = true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(lefttoRight){
                if(temp->left)
                    nextLevel.push(temp->left);
            
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            //Right to left
            else{
                if(temp->right)
                    nextLevel.push(temp->right);

                if(temp->left)
                    nextLevel.push(temp->left);
            } 
        }
        if(currLevel.empty()){
            lefttoRight = !lefttoRight;
            swap(currLevel, nextLevel);
        }
    }
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    zigzagTraversal(root); 
   return 0;
}


