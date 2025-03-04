#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void append(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current == head) {
                    head = current->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    Node* prevNode = current->prev;
                    Node* nextNode = current->next;
                    if (prevNode) prevNode->next = nextNode;
                    if (nextNode) nextNode->prev = prevNode;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void insert(int value, int prevValue) {
        Node* current = head;
        while (current) {
            if (current->data == prevValue) {
                Node* newNode = new Node{value, nullptr, nullptr};
                if (current->next) {
                    newNode->next = current->next;
                    newNode->prev = current;
                    current->next = newNode;
                    if (newNode->next) newNode->next->prev = newNode;
                } else {
                    newNode->prev = current;
                    current->next = newNode;
                }
                tail = newNode;
                return;
            }
            current = current->next;
        }
    }

    void printForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    cout << "Pushing 10: ";
    dll.push(10);
    dll.printForward();

    cout << "Pushing 20: ";
    dll.push(20);
    dll.printForward();

    cout << "Pushing 30: ";
    dll.push(30);
    dll.printForward();

    cout << "Appending 40: ";
    dll.append(40);
    dll.printForward();

    cout << "Forward traversal: ";
    dll.printForward();

    cout << "Backward traversal: ";
    dll.printBackward();

    cout << "Inserting 25 after 20: ";
    dll.insert(25, 20);
    dll.printForward();

    cout << "Deleting 20: ";
    dll.deleteNode(20);
    dll.printForward();

    return 0;
}
