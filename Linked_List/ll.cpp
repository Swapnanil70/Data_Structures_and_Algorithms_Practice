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
void deleteAtBeg(node* &head){
    node* temp = head;
    head = head->next;
    delete temp;
}
void deleteWithValue(node* head, int value){

    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtBeg(head);
        return;
    }
    node* temp = head;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node* p = temp->next;
    temp->next = temp->next->next;
    delete p;    
}
void search(node* head, int key){

    node* temp = head;
    int i = 1, flag = 0;
    while (temp->next != NULL )
    {
        /* code */
        if (temp->data == key)
        {
            cout<<"Value found at "<<i<<endl;
            flag = 1;
            break;
        }
        temp = temp->next;
        i++;
    }
    if (flag == 0)
    {
        /* code */
        cout<<"Value not found"<<endl;
    }
}

void printList(node* head){
    node* temp = head; 
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
//reverse a linked list using iterative approach
node* revitr(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next;

    while ( curr!= NULL )
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
//reversing using recursion
node* revrec(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = revrec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;

}
// reverse k nodes in a linked list
node* reversek(node* &head, int k){

    node* prev = NULL;
    node* curr = head;
    node* next;

    int count = 0;
    while (curr != NULL && count < k)
    {
        /* code */
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++; 
    }
    
    if (next != NULL)
    {
        /* code */
        head->next = reversek(next, k);
    }
    
    return prev;

}
void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;

}

// Floyds Algorithm
bool detectcycle(node* head){
    node* fast = head;
    node* slow = head;

    while (true)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
        if (fast->next == NULL || fast == NULL)
        {
            return  false;
        }
    }
}
// remove cycle
void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;

    while (true){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            /* code */
            fast = head;
            break;
        }
    }
    while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
    slow->next = NULL;
}

int main()
{
    node* head = NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head, 10);
    insertatTail(head, 6);
    insertatTail(head, 7);
    // search(head, 2);
    // printList(head);
    // deleteAtBeg(head);
    // printList(head);
    // node* newhead = revitr(head);
    // node* newhead = revrec(head);
    // node* newhead = reversek(head, 2);
    // printList(newhead);
    makeCycle(head, 4);
    cout<<detectcycle(head)<<endl; 
    removeCycle(head);
    cout<<detectcycle(head)<<endl; 
    printList(head);
    return 0;
}