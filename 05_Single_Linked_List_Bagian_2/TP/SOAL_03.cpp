#include <iostream>
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

void insert(Node*& head, int v) {
    Node* node = new Node(v);
    
    if (!head || head->val >= v) {
        node->next = head;
        head = node;
        return;
    }
    
    Node* curr = head;
    while (curr->next && curr->next->val < v) {
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
}

void print(Node* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    Node* head = nullptr;
    std::cout << "Enter 4 elements in order:\n";
    
    for (int i = 0; i < 4; i++) {
        int v;
        std::cout << i+1 << ": ";
        std::cin >> v;
        insert(head, v);
    }
    
    std::cout << "Current list: ";
    print(head);
    
    std::cout << "Enter new element: ";
    int v;
    std::cin >> v;
    insert(head, v);
    
    std::cout << "Updated list: ";
    print(head);
}