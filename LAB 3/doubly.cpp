//NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
//22011748


#include <iostream>
using namespace std;

struct DNode {
    string name;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
    DNode* head = nullptr;
    DNode* tail = nullptr;

public:
    void insert_node_by_name(string name) {
        DNode* node = new DNode{name, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void delete_node_by_value(string name) {
        DNode* current = head;
        while (current != nullptr && current->name != name) {
            current = current->next;
        }

        if (current == nullptr) return;

        if (current == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
    }

    void display_list() {
        DNode* curr = head;
        while (curr != nullptr) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
};

int main() {
    DoublyLinkedList std_names;

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
