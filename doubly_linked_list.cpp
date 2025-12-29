#include <iostream>
#include <string>

using namespace std;

// Node class for any kind of inputs
template <typename T>
class Node {
   public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked list class for different operations
template <typename T>
class DoublyLinkedList {
   private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

   public:
    // Check if list is empty
    bool isEmpty() { return head == nullptr; }

    // Insertion at the beginning
    void insertAtBeg(const T& value) {

        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    // Insertion at the end
    void insertAtEnd(const T& value) {

        Node<T>* newNode = new Node(value);

        if (isEmpty()) {
            insertAtBeg(value);
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    // Insertion at position
    void insertAtPos(const T& value, int pos) {

        if (pos < 1) {
            cout << "Invalid Position!\nPosition must be greater than 0." << endl;
            return;
        } else if (pos == 1) {
            insertAtBeg(value);
            return;
        } else if (pos > size + 1) {
            cout << "Position " << pos << " out of bound!" << endl;
            return;
        } else if (pos == size + 1) {
            insertAtEnd(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    // Deletion at the beginning
    void deleteAtBeg() {
        if (isEmpty()) {
            cout << "List is empty!\nNo elements to delete." << endl;
            return;
        }

        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
    }

    // Deletion at the end
    void deleteAtEnd() {

        if (isEmpty()) {
            cout << "List is empty!\nNo elements to delete." << endl;
            return;
        }

        Node<T>* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
    }

    // Deletion at any position
    void deleteAtPos(int pos) {
        if (pos < 1) {
            cout << "Invalid position.\nPosition must be greater than 0." << endl;
            return;
        } else if (pos == 1) {
            deleteAtBeg();
            return;
        } else if (pos > size) {
            cout << "Position " << pos << " out of bound!" << endl;
            return;
        } else if (pos == size) {
            deleteAtEnd();
            return;
        }


        Node<T>* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    // Display the list
    void display() {

        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = head;

        while (temp != nullptr) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        
        cout << "NULL" << endl;
        cout << "Size: " << size << endl;
    }

    // Create a linkedlist
    void create(int num) {
        T item;
        for (int i = 1; i <= num; i++) {
            cout << "Enter element " << i << " : ";
            cin >> item;
            insertAtEnd(item);
        }
    }
};

template <typename T>
void displayOperationMenu(DoublyLinkedList<T>& list) {

    int ctrl, position;
    T value;
    while (true) {
        cout << "\n========================================\n";
        cout << "   DOUBLY LINKED LIST OPERATIONS\n";
        cout << "========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "8. Return to Main Menu\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> ctrl;

        switch (ctrl) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeg(value);
                cout << "Element inserted Successfully." << endl;
                break;
            }
            case 2: {
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                cout << "Element inserted Successfully." << endl;
                break;
            }
            case 3: {
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPos(value, position);
                cout << "Element inserted Successfully." << endl;
                break;
            }
            case 4: {
                list.deleteAtBeg();
                cout << "Element Deleted Successfully." << endl;
                break;
            }
            case 5: {
                list.deleteAtEnd();
                cout << "Element Deleted Successfully." << endl;
                break;
            }
            case 6: {
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPos(position);
                cout << "Element Deleted Successfully." << endl;
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                cout << "Returning!\n";
                return;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

template <typename T>
void createAndOperateList() {
    DoublyLinkedList<T> list;

        int numElements;
        cout << "How many elements do you want to add initially? ";
        cin >> numElements;

        if (numElements > 0) {
            list.create(numElements);
        }

    displayOperationMenu(list);
}

void createDefaultList() {

    DoublyLinkedList<int> list;  

    for(int i = 1; i <= 5; i++) {
        list.insertAtEnd(i);
    }

    displayOperationMenu(list); 
}

void mainMenu() {
    int choice;

    while (true) {
        cout << "\n========================================";
        cout << "\n   DOUBLY LINKED LIST MENU";
        cout << "\n========================================";
        cout << "\n1. Create a list of integers";
        cout << "\n2. Create a list of doubles";
        cout << "\n3. Create a list of strings";
        cout << "\n4. Create a list of characters";
        cout << "\n5. Use predefined demo lists (1, 2, 3, 4, 5)";
        cout << "\n6. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAndOperateList<int>();
                break;
            case 2:
                createAndOperateList<double>();
                break;
            case 3:
                createAndOperateList<string>();
                break;
            case 4:
                createAndOperateList<char>();
                break;
            case 5:
                createDefaultList();
                break;
            case 6:
                cout << "Exiting... Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

int main () {
    
    mainMenu();
    return 0;
}