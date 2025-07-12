// NUR AMNI SYAZWANI BINTI MOHAMAD NASIR
// 22011748

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name, Node* next = nullptr, Node* prev = nullptr) {
        this->name = name;
        this->next = next;
        this->prev = prev;
    }
};

class DoublyCircularList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert_node_by_name(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = tail = new_node;
            head->next = head;
            head->prev = head;
        } else {
            new_node->next = head;
            new_node->prev = tail;
            tail->next = new_node;
            head->prev = new_node;
            tail = new_node;
        }
    }

    void delete_node_by_value(string name) {
        if (!head) return;

        Node* current = head;
        do {
            if (current->name == name) {
                if (current == head && current == tail) {
                    // Only one node
                    delete current;
                    head = nullptr;
                    tail = nullptr;
                    return;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    if (current == head)
                        head = current->next;
                    if (current == tail)
                        tail = current->prev;

                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
    }

    void display_list() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    Node* get_head() {
        return head;
    }
};

int main() {
    DoublyCircularList std_names;

    std_names.insert_node_by_name("Ali");
    std_names.insert_node_by_name("Alice");
    std_names.insert_node_by_name("Ahmed");

    cout << "Before delete:" << endl;
    std_names.display_list();

    std_names.delete_node_by_value("Alice");

    cout << "\nAfter delete:" << endl;
    std_names.display_list();

    // Cleanup
    if (std_names.get_head()) {
        Node* current = std_names.get_head();
        Node* start = current;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != start);
    }

    return 0;
}
