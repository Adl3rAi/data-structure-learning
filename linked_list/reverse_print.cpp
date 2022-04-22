#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void Print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* insert(int x, Node* head) {
    Node* temp = new Node();
    temp->data = x;
    if(head != NULL) {
        temp->next = head;
    }
    head = temp;
    return head;
}
void reversePrint(Node* head) {
    Node* temp = head;
    if(temp != NULL) {
        if(temp->next != NULL) {
            reversePrint(temp->next);
        }
        cout << temp->data << " ";
    }
}
int main()
{
    Node* head = NULL;
    for(int i = 0; i < 5; i++) {
        head = insert(i, head);
    }
    Print(head);
    cout << endl;
    reversePrint(head);
}