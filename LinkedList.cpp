#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* next;
};

void print(Node* n) {
    while(n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

void insertAtTheFront(Node** head, int newValue) {
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTheEnd(Node** head, int newValue) {
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void insertAfter(Node* previous, int newValue) {
    if(previous == NULL) {
        cout << "Previous can not be NULL" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->value = newValue;
    
    newNode->next = previous->next;
    previous->next = newNode;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = NULL;


    insertAfter(head, -5);
    insertAtTheFront(&head, -1);
    insertAtTheEnd(&head, 6);
    print(head);
    return 0;
}