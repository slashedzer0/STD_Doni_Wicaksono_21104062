#include <iostream>
struct Node {
   int val;
   Node *prev, *next;
   Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

void addFirst(Node*& head, int v) {
   Node* node = new Node(v);
   node->next = head;
   if (head) head->prev = node;
   head = node;
}

void addLast(Node*& head, int v) {
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

void print(Node* head) {
   std::cout << "List: ";
   while (head) {
       std::cout << head->val;
       if (head->next) std::cout << " <-> ";
       head = head->next;
   }
   std::cout << "\n";
}

int main() {
   Node* head = nullptr;
   int v;
   
   std::cout << "First element: ";
   std::cin >> v;
   addLast(head, v);
   print(head);
   
   std::cout << "Second element (front): ";
   std::cin >> v;
   addFirst(head, v);
   print(head);
   
   std::cout << "Third element (back): ";
   std::cin >> v;
   addLast(head, v);
   print(head);
}