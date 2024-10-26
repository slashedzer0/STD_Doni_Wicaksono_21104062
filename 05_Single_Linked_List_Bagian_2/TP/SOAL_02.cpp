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

void print(Node* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void sort(Node* head) {
    if (!head) return;
    
    Node* last = nullptr;
    bool swapped;
    
    do {
        swapped = false;
        Node* curr = head;
        
        while (curr->next != last) {
            if (curr->val > curr->next->val) {
                std::swap(curr->val, curr->next->val);
                swapped = true;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    std::cout << "Enter 5 elements:\n";
    
    for (int i = 0; i < 5; i++) {
        int v;
        std::cout << i+1 << ": ";
        std::cin >> v;
        add(head, v);
    }
    
    std::cout << "Before sort: ";
    print(head);
    sort(head);
    std::cout << "After sort: ";
    print(head);
}