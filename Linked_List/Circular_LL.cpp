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
    node* temp = head;
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
     while (temp->next != head)
    {
        /* code */
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insertatTail(node* &head, int value){
    node* n = new node(value);
    if (head == NULL)
    {
        insertatHead(head, value);
        return;
    }
    node* temp = head;
    while (temp->next != head)
    {
        /* code */
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void print(node* &head){
    node* temp = head;
    do
    {
        /* code */
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}
void deleteAthead(node* &head){
    node* temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node* ptr = head;
    temp->next = head->next;
    head = head->next;

    delete ptr;
}
void deletion(node* &head, int pos){
    
    if (pos == 1)
    {
        deleteAthead(head);
        return;
    }
    node* temp = head;
    int count = 1;

    while (count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    node* ptr = temp->next;
    temp->next = temp->next->next;
    delete ptr;
}
int main()
{
    node* head = NULL;
    for (int i = 1; i < 6; i++)
    {
        /* code */
        insertatTail(head, i);
    }
    print(head);
    // insertatHead(head, 6);
    // print(head);
    deletion(head, 1);
    print(head);
    return 0;
}