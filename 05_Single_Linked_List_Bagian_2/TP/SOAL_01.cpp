#include <iostream>
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

void add(Node*& head, int v) {
    if (!head) {
        head = new Node(v);
        return;
    }
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = new Node(v);
}

void find(Node* head, int v) {
    Node* curr = head;
    int pos = 1;
    
    while (curr) {
        if (curr->val == v) {
            std::cout << v << " found at address " << curr << ", position " << pos << "\n";
            return;
        }
        curr = curr->next;
        pos++;
    }
    std::cout << v << " not found\n";
}

int main() {
    Node* head = nullptr;
    std::cout << "Enter 6 elements:\n";
    
    for (int i = 0; i < 6; i++) {
        int v;
        std::cout << i+1 << ": ";
        std::cin >> v;
        add(head, v);
    }
    
    int target;
    std::cout << "Search for: ";
    std::cin >> target;
    find(head, target);
}