#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a sentinel value to indicate error
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate error
        }
        return top->data;
    }

    bool isEmpty() const {
        return (top == nullptr);
    }

    int getSize() const {
        return size;
    }

    void printStack() const {
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the stack
    cout << "Stack elements: ";
    myStack.printStack();

    // Peek the top element
    cout << "Top element: " << myStack.peek() << endl;

    // Pop elements
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    // Check if empty
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    // Push another element
    myStack.push(40);

    // Print the stack
    cout << "Stack elements after pushing 40: ";
    myStack.printStack();

    // Get the size
    cout << "Stack size: " << myStack.getSize() << endl;

    return 0;
}
