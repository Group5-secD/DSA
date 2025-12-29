#include <iostream>
using namespace std;

// node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value);
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(std::initializer_list<int> list) {
        head = tail = nullptr;
        for (int value : list) {
           // insertAtEnd(value);
        }
    }

    // INSERT operations
    void insertAtBeginning(int value);
    void insertAtPosition(int value, int position);
    void insertAtEnd(int value);

    // DELETE operations
    void deleteAtBeginning();
    void deleteAtPosition(int position);

    void deleteAtEnd() {
        if (tail == nullptr) {  // Empty list
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = tail;

        if (head == tail) { // Only one node
            head = tail = nullptr;
        } else { // More than one node
            tail = tail->prev;       // Move tail pointer safely
            tail->next = nullptr;    // Disconnect old last node
        }

        cout << "Deleted " << temp->data << " from the end.\n";
        delete temp;     
}

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list = {10, 20, 30, 40, 50};

    // Sample operations
    // list.insertAtBeginning(10);
    // list.insertAtPosition(15, 2);
    // list.insertAtEnd(20);

    // list.deleteAtBeginning();
    // list.deleteAtPosition(1);
    list.deleteAtEnd();

    list.display();

    return 0;
}
