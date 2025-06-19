//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
//22011748

#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next_pointer;
};

class LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void insert_node_by_name(string name) {
        Node* node = new Node{name, nullptr};
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next_pointer = node;
            tail = node;
        }
    }

    void delete_node_by_value(string name) {
        if (head == nullptr) return;

        // If head needs to be deleted
        if (head->name == name) {
            Node* temp = head;
            head = head->next_pointer;
            if (head == nullptr) tail = nullptr;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next_pointer != nullptr && current->next_pointer->name != name) {
            current = current->next_pointer;
        }

        if (current->next_pointer != nullptr) {
            Node* temp = current->next_pointer;
            current->next_pointer = temp->next_pointer;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << endl;
            currNode = currNode->next_pointer;
        }
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

    return 0;
}
