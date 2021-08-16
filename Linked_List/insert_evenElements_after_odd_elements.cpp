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
void evenAfterOdd(node* &head){
    node *odd = head;
    node *even = head->next;
    node* evenstart = head->next;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    if (odd->next == NULL)
    {
        odd->next = evenstart;
        even->next = NULL;
    }
    if (even->next == NULL)
    {
        odd->next = evenstart;
        even->next = NULL;
    }
    // odd->next = evenstart;
    // if (odd->next!=NULL)
    // {
    //     /* code */
    //     even->next = NULL;
    // }
}
void printList(node* head){
    node* temp = head; 
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head = NULL;
    for (int i = 1; i < 11; i++)
    {
        /* code */
        insertatTail(head, i);
    }
    printList(head);
    evenAfterOdd(head);
    printList(head);
    return 0;
}
