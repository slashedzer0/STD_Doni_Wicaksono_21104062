#include <iostream>
struct Node {
   int val;
   Node *prev, *next;
   Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

void add(Node*& head, int v) {
   if (!head) {
       head = new Node(v);
       return;
   }
   
   Node* curr = head;
   while (curr->next) curr = curr->next;
   
   Node* node = new Node(v);
   curr->next = node;
   node->prev = curr;
}

void printFwd(Node* head) {
   std::cout << "Forward: ";
   while (head) {
       std::cout << head->val;
       if (head->next) std::cout << " <-> ";
       head = head->next;
   }
   std::cout << "\n";
}

void printRev(Node* head) {
   if (!head) return;
   
   Node* curr = head;
   while (curr->next) curr = curr->next;
   
   std::cout << "Reverse: ";
   while (curr) {
       std::cout << curr->val;
       if (curr->prev) std::cout << " <-> ";
       curr = curr->prev;
   }
   std::cout << "\n";
}

int main() {
   Node* head = nullptr;
   int v;
   
   for (int i = 1; i <= 4; i++) {
       std::cout << "Element " << i << ": ";
       std::cin >> v;
       add(head, v);
   }
   
   printFwd(head);
   printRev(head);
}