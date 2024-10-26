#include <iostream>
#include <string>

struct Book {
   int id;
   std::string title, author;
   Book *prev, *next;
   Book(int i, std::string t, std::string a) : 
       id(i), title(t), author(a), prev(nullptr), next(nullptr) {}
};

class BookList {
private:
   Book* head;
   
public:
   BookList() : head(nullptr) {}
   
   void add(int id, std::string title, std::string author) {
       Book* book = new Book(id, title, author);
       
       if (!head) {
           head = book;
           return;
       }
       
       Book* curr = head;
       while (curr->next) curr = curr->next;
       
       curr->next = book;
       book->prev = curr;
   }
   
   void printFwd() {
       if (!head) {
           std::cout << "Empty list\n";
           return;
       }
       
       std::cout << "\nBooks (Front to Back):\n";
       Book* curr = head;
       while (curr) {
           std::cout << "ID: " << curr->id << "\n"
                    << "Title: " << curr->title << "\n"
                    << "Author: " << curr->author << "\n\n";
           curr = curr->next;
       }
   }
   
   void printRev() {
       if (!head) {
           std::cout << "Empty list\n";
           return;
       }
       
       Book* curr = head;
       while (curr->next) curr = curr->next;
       
       std::cout << "\nBooks (Back to Front):\n";
       while (curr) {
           std::cout << "ID: " << curr->id << "\n"
                    << "Title: " << curr->title << "\n"
                    << "Author: " << curr->author << "\n\n";
           curr = curr->prev;
       }
   }
};

int main() {
   BookList list;
   int n, id;
   std::string title, author;
   
   std::cout << "Number of books: ";
   std::cin >> n;
   std::cin.ignore();
   
   for (int i = 1; i <= n; i++) {
       std::cout << "\nBook " << i << ":\n";
       std::cout << "ID: ";
       std::cin >> id;
       std::cin.ignore();
       
       std::cout << "Title: ";
       std::getline(std::cin, title);
       
       std::cout << "Author: ";
       std::getline(std::cin, author);
       
       list.add(id, title, author);
   }
   
   list.printFwd();
   list.printRev();
}