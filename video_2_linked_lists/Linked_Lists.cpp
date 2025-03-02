#include <iostream>
#include <string>

using namespace std;

// Define the structure for a linked list node
struct Node {
    char data;
    Node* next;
    
    // Constructor to initialize node with data and set next to nullptr
    Node(char value) {
        data = value;
        next = nullptr;
    }
};

// Function to print node details with memory addresses
void printNodeDetails(Node* node) {
    if (node == nullptr) {
        cout << "Node is nullptr" << endl;
        return;
    }
    
    cout << "Node Address: " << node 
         << ", Data: " << node->data 
         << ", Next Pointer Address: " << node->next 
         << endl;
}

// Function to print the node sequence in a simple format
void printNodeSequence(Node* head) {
    if (head == nullptr) {
        cout << "nullptr" << endl;
        return;
    }
    
    string sequence = "Node ";
    sequence += head->data;
    
    Node* current = head->next;
    while (current != nullptr) {
        sequence += " -> Node ";
        sequence += current->data;
        current = current->next;
    }
    
    sequence += " -> nullptr";
    cout << sequence << endl;
}

// Function to print a single node's data in a pretty format
void printPrettyNode(Node* node) {
    if (node == nullptr) {
        cout << "Node is nullptr" << endl;
        return;
    }
    
    cout << "Node " << node->data << endl;
}

int main() {
    // Create the nodes with character data
    Node A('A');   // Node A with data 'A'
    Node B('B');   // Node B with data 'B'
    Node C('C');   // Node C with data 'C'
    Node D('D');   // Node D with data 'D'
    Node E('E');   // Node E with data 'E'

    // Set up the pointers as specified
    D.next = &B;   // D points to B
    B.next = &E;   // B points to E
    E.next = &C;   // E points to C
    C.next = nullptr; // C points to nothing
    A.next = nullptr; // A points to nothing

    // Print details of specific nodes before the main printing logic
    cout << "Printing the details of some of our nodes" << endl;
    printNodeDetails(&B);
    printNodeDetails(&D);
    cout << "Continue the rest of our program" << endl;
    cout << endl;

    // Print pretty versions of B and D
    cout << "Pretty version of Node B:" << endl;
    printPrettyNode(&B);
    cout << "Pretty version of Node D:" << endl;
    printPrettyNode(&D);
    cout << endl;

    // Set the start of the linked list to D
    Node* start = &D;

    // Print the linked list with memory details
    cout << "Detailed Node Information:" << endl;
    Node* current = start;
    while (current != nullptr) {
        printNodeDetails(current);
        current = current->next;
    }

    // Print the linked list in a simple sequence format
    cout << "\nSimple Node Sequence:" << endl;
    printNodeSequence(start);

    // Print node A (which is not connected to the main list)
    cout << "\nNode A (not connected to the main list):" << endl;
    printNodeDetails(&A);
    cout << endl;
    printNodeSequence(&A);

    return 0;
}
