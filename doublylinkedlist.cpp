#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

void insertAtPosition(Node*& head, int data, int index) {
    Node* newNode = new Node();
    newNode->value = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (index == 1) {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < index - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 15, 2);

    display(head);
    return 0;
}
