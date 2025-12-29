#include <iostream>
using namespace std;

// node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(std::initializer_list<int> list) {
        head = tail = nullptr;
        for (int value : list) {
            insertAtEnd(value);
        }
    }

    // INSERT operations
    void insertAtBeginning(int value);
    void insertAtPosition(int value, int position);
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // DELETE operations
    void deleteAtBeginning();

    // 🔹 YOUR deletion at any position (same logic as you wrote earlier)
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            head = temp->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position";
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void deleteAtEnd() {
        if (tail == nullptr) {  
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = tail;

        if (head == tail) { 
            head = tail = nullptr;
        } else { 
            tail = tail->prev;
            tail->next = nullptr;
        }

        cout << "Deleted " << temp->data << " from the end/.\n";
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

    // list.deleteAtPosition(3);   // ← YOUR part
    list.deleteAtEnd();

    list.display();
    return 0;
}
