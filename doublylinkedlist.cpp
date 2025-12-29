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
    void insertAtPosition(int data, int index) {
        if (index < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (index == 1) {
            Node* newNode = new Node(data);
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr) // If list was empty, head is also tail
                tail = head;
            return;
        }

        Node* temp = head;
        // Traverse to the node before the insertion point
        for (int i = 1; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            // Inserting at the end, update tail
            tail = newNode;
        }

        temp->next = newNode;
    }
    void insertAtEnd(int value);
    // DELETE operations
    void deleteAtBeginning();
    void deleteAtAnyPosition(int pos) {
        if (pos < 1 || head == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* curr = head;

        // Traverse to the node to be deleted
        for (int i = 1; i < pos && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (curr == head) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr; // List becomes empty
        } else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        cout << "Deleted " << curr->data << " from position " << pos << endl;
        delete curr;
    }

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
    int choice, value, position;

    while (true) {
        cout << "\n========================================\n";
        cout << "   DOUBLY LINKED LIST MENU\n";
        cout << "========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                //list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                //list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                //list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtAnyPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
