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
        if (!node) return;

        node->next_ptr = nullptr;

        if (!front) {
            front = rear = node;
        } else {
            rear->next_ptr = node;
            rear = node;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removing: " << temp->name << endl;
        front = front->next_ptr;

        if (!front) rear = nullptr;

        delete temp;
    }

    void display_queue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        while (current) {
            cout << current->name << " <- ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

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
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    queue.display_queue();

    // Dequeue example
    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    // Clean up memory
    Node* current = queue.get_front();
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}
