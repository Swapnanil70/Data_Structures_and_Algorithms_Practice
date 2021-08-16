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
void makeIntersection(node* &head1, node* head2, int pos){
    node* temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(node* &head1, node* head2){
    node* ptr1;
    node* ptr2;
    int l1, l2, diff;
    l1 = len(head1);
    l2 = len(head2);
    if(l1>l2){
        diff = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (diff)
    {
        diff--;
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return-1;
    }
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    /* code */
    node* head1 = NULL;
    node* head2 = NULL;
    for (int i = 1; i <= 5; i++)
    {
        /* code */
        insertatTail(head1, i);
    }
    printList(head1);
    for (int i = 10; i < 16; i++)
    {
        insertatTail(head2, i);
    }
    printList(head2);
    makeIntersection(head1, head2, 3);
    printList(head1);
    printList(head2);
    cout<<intersection(head1, head2);
    return 0;
}