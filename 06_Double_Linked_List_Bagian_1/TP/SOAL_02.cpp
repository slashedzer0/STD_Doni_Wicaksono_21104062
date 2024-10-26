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

void popFirst(Node*& head) {
   if (!head) {
       std::cout << "Empty list\n";
       return;
   }
   
   Node* temp = head;
   head = head->next;
   if (head) head->prev = nullptr;
   delete temp;
}

void popLast(Node*& head) {
   if (!head) {
       std::cout << "Empty list\n";
       return;
   }
   
   if (!head->next) {
       delete head;
       head = nullptr;
       return;
   }
   
   Node* curr = head;
   while (curr->next) curr = curr->next;
   curr->prev->next = nullptr;
   delete curr;
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
   add(head, v);
   print(head);
   
   std::cout << "Second element: ";
   std::cin >> v;
   add(head, v);
   print(head);
   
   std::cout << "Third element: ";
   std::cin >> v;
   add(head, v);
   print(head);
   
   std::cout << "=================\n";
   std::cout << "Removing first and last:\n";
   popFirst(head);
   popLast(head);
   print(head);
}