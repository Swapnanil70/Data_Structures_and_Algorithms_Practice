#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int value){
        data = value;
        next = NULL;
    }
};

void insertatHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;
}

void insertatTail(node* &head, int value){
    node* n = new node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        /* code */
        temp = temp->next;
    }
    temp->next = n;
}
void printList(node* head){
    node* temp = head; 
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int len(node* head){
    node* temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = len(head);
    k = k%l;
    int count = 1;
    while (tail->next != NULL)
    {
        if(count == l-k)
            newTail = tail;

        if(count == l-k+1)
            newHead = tail;

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}
int main(int argc, char const *argv[])
{
    /* code */
    node* head = NULL;
    for (int i = 1; i <= 5; i++)
    {
        /* code */
        insertatTail(head, i);
    }
    printList(head);
    node* newhead = kappend(head, 2);
    printList(newhead);
    return 0;
}
