//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
//22011748

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(Node* node) {
        if (!node)
            return;

        if (!front) {
            front = rear = node;
            node->next_ptr = front; // Circular link
        } else {
            rear->next_ptr = node;
            rear = node;
            rear->next_ptr = front; // Maintain circular connection
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            cout << "Removing: " << front->name << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Removing: " << temp->name << endl;
            front = front->next_ptr;
            rear->next_ptr = front;
            delete temp;
        }
    }

    void display_queue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->name << " <- ";
            current = current->next_ptr;
        } while (current != front);

        cout << "Front (" << front->name << ")" << endl;
    }

    // Clean-up helper
    Node* get_front() const {
        return front;
    }
};

int main() {
    // Create nodes dynamically
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");
    Node* node4 = new Node("Abu");

    // Create queue and add nodes
    Queue queue;
    queue.enqueue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3)
