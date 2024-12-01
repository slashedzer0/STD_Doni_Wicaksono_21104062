#include <iostream>
#include <limits>
using namespace std;

struct Node {
    char d;
    Node *l, *r, *p;
};

Node *root, *tmp;

void init() { root = NULL; }
bool empty() { return !root; }

void mkRoot(char d) {
    if (empty()) {
        root = new Node{d, NULL, NULL, NULL};
        cout << "Node " << d << " is now Root\n";
    } else cout << "Tree exists\n";
}

Node* addLeft(char d, Node* n) {
    if (empty()) {
        cout << "Tree not created\n";
        return NULL;
    }
    if (n->l) {
        cout << "Node " << n->d << " has left child\n";
        return NULL;
    }
    tmp = new Node{d, NULL, NULL, n};
    n->l = tmp;
    cout << "Node " << d << " added left of " << n->d << "\n";
    return tmp;
}

Node* addRight(char d, Node* n) {
    if (empty()) {
        cout << "Tree not created\n";
        return NULL;
    }
    if (n->r) {
        cout << "Node " << n->d << " has right child\n";
        return NULL;
    }
    tmp = new Node{d, NULL, NULL, n};
    n->r = tmp;
    cout << "Node " << d << " added right of " << n->d << "\n";
    return tmp;
}

void showDesc(Node* n) {
    if (!n) {
        cout << "Node not found\n";
        return;
    }
    cout << "Descendants of " << n->d << ": ";
    if (n->l) cout << n->l->d << " ";
    if (n->r) cout << n->r->d << " ";
    if (!n->l && !n->r) cout << "(No children)";
    cout << "\n";
}

bool isBST(Node* n, char min = numeric_limits<char>::min(), char max = numeric_limits<char>::max()) {
    if (!n) return true;
    if (n->d <= min || n->d >= max) return false;
    return isBST(n->l, min, n->d) && isBST(n->r, n->d, max);
}

int leafCount(Node* n) {
    if (!n) return 0;
    if (!n->l && !n->r) return 1;
    return leafCount(n->l) + leafCount(n->r);
}

void menu() {
    int c;
    char d, pd;
    Node* pn;
    do {
        cout << "\nBinary Tree Menu:\n"
             << "1. Create Root\n2. Add Left Node\n"
             << "3. Add Right Node\n4. Show Descendants\n"
             << "5. Check BST\n6. Count Leaves\n7. Exit\n"
             << "Choose: ";
        cin >> c;

        switch(c) {
            case 1:
                cout << "Enter Root data: ";
                cin >> d;
                mkRoot(d);
                break;
            case 2:
                cout << "Enter Parent data: ";
                cin >> pd;
                pn = root;
                if (pn->d == pd) {
                    cout << "Enter Left Node data: ";
                    cin >> d;
                    addLeft(d, pn);
                }
                break;
            case 3:
                cout << "Enter Parent data: ";
                cin >> pd;
                pn = root;
                if (pn->d == pd) {
                    cout << "Enter Right Node data: ";
                    cin >> d;
                    addRight(d, pn);
                }
                break;
            case 4:
                cout << "Enter Node data: ";
                cin >> d;
                showDesc(root);
                break;
            case 5:
                cout << (isBST(root) ? "Tree is BST\n" : "Tree is not BST\n");
                break;
            case 6:
                cout << "Leaf count: " << leafCount(root) << "\n";
                break;
            case 7:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(c != 7);
}

int main() {
    init();
    menu();
    return 0;
}