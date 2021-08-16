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
node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummmyNode = new node(-1);
    node* p3 = dummmyNode; 
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummmyNode->next;
}
node* mergeRec(node* head1, node* head2){
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 = NULL)
    {
        return head1;
    }
    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRec(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRec(head1, head2->next);
    }
    return result;
}
int main(int argc, char const *argv[])
{
    /* code */
    node* head1 = NULL;
    node* head2 = NULL;
    for (int i = 1; i <= 10; i+=2)
    {
        /* code */
        insertatTail(head1, i);
    }
     for (int i = 0; i <= 10; i+=2)
    {
        /* code */
        insertatTail(head2, i);
    }
    printList(head1);
    printList(head2);
    // node* newhead = merge(head1, head2);
    node* newhead = merge(head1, head2);
    printList(newhead);
    return 0;
}