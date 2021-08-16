#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* prev;
    node* next;
    node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};
void insertatHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    if(head != NULL)
        head->prev = n;
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
    while (temp->next != NULL)
    {
        /* code */
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void deleteatHead(node* &head){
    node* temp = head;
    head = head->next;
    head->prev = NULL;

    delete temp;
}
void deletewithpos(node* &head, int pos){

    if(pos == 1){
        deleteatHead(head);
        return;
    }

    node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}
void printList(node* head){
    node* temp = head; 
    cout<<"NULL<-";
    while (temp != NULL){
        cout<<temp->data<<"-><-";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head = NULL;
    insertatTail(head, 1);
    insertatHead(head, 5);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 6);
    printList(head);
    // deletewithpos(head, 2);
    deletewithpos(head, 1);
    printList(head);
    return 0;
}