#include <iostream>
using namespace std;

// Node class definition 
class Node {
public:
    int data;
    Node* next;

   //constructor for Node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked list operations
class LinkedList {
private:
    Node* head;

public:
    //constructor for list
    LinkedList() {
        head = NULL;
    }

    // Insert a node at the end
    void insert(int val) {
        Node* p = new Node(val); // p is used for new node
        if (head == NULL) {
            head = p;
        } else {
            Node* q = head; // q is used for traversal
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }

    // Delete a node by value
    void remove(int val) {
        Node* p = NULL;
        Node* q = head;

        // If head node itself holds the value
        if (q!=NULL && q->data == val) {
            p = head;
            head = head->next;
            delete p;
            return;
        }

        // Traverse to find the node
        while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                delete p;
                return;
            }
            q = q->next;
        }

        cout <<endl<< "Value " << val << " not found in the list.\n";
    }

    // Display the list
    void display() {
        cout<<endl<<"Linked List ";
        Node* q = head;
        while (q != NULL) {
            cout << q->data << " -> ";
            q = q->next;
        }
        //cout << "NULL\n";
    }
};

// Main function to test the linked list
int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display(); // Output: 10 -> 20 -> 30 -> NULL
    
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.display();
    
    list.remove(40);
    list.display(); 

    list.remove(60); 
    list.display();

    list.remove(100); 
    list.display();

    return 0;
}
