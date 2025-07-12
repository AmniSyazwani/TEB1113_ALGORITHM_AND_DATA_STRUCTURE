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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert_node_by_name(string name) {
        Node* new_node = new Node(name);

        if (!head) {
            head = tail = new_node;
            new_node->next_ptr = head; // Make it circular
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head; // Maintain circular connection
        }
    }

    void delete_node_by_value(string name) {
        if (!head) return;

        Node* current = head;
        Node* previous = tail;
        bool found = false;

        do {
            if (current->name == name) {
                found = true;
                break;
            }
            previous = current;
            current = current->next_ptr;
        } while (current != head);

        if (!found) return;

        if (head == tail && head->name == name) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            previous->next_ptr = current->next_ptr;

            if (current == head) head = current->next_ptr;
            if (current == tail) tail = previous;

            delete current;
        }
    }

    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "head (" << head->name << ")" << endl;
    }

    Node* get_head() const {
        return head;
    }

    Node* get_tail() const {
        return tail;
    }
};

int main() {
    LinkedList std_names;

    std_names.insert_node_by_name("Ali");
    std_names.insert_node_by_name("Alice");
    std_names.insert_node_by_name("Ahmed");

    cout << "Before delete:\n";
    std_names.display_list();

    std_names.delete_node_by_value("Alice");

    cout << "\nAfter delete:\n";
    std_names.display_list();

    // Clean up memory
    Node* head = std_names.get_head();
    Node* tail = std_names.get_tail();

    if (head) {
        Node* current = head->next_ptr;
        while (current != head) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
        delete head;
    }

    return 0;
}
