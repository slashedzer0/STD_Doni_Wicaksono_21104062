#include <iostream>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil menjadi Root" << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *Node)
{
    if (isEmpty())
    {
        cout << "\nPohon belum dibuat" << endl;
        return NULL;
    }
    if (Node->left != NULL)
    {
        cout << "\nNode " << Node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << Node->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *Node)
{
    if (isEmpty())
    {
        cout << "\nPohon belum dibuat" << endl;
        return NULL;
    }
    if (Node->right != NULL)
    {
        cout << "\nNode " << Node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kanan " << Node->data << endl;
    return baru;
}

void update(char data, Pohon *Node)
{
    if (isEmpty())
    {
        cout << "\nPohon belum dibuat" << endl;
        return;
    }
    if (!Node)
    {
        cout << "\nNode tidak ditemukan" << endl;
        return;
    }
    char temp = Node->data;
    Node->data = data;
    cout << "\nData " << temp << " berhasil diubah" << endl;
}

void retrieve(Pohon *Node)
{
    if (isEmpty())
    {
        cout << "\nPohon belum dibuat" << endl;
        return;
    }
    if (!Node)
    {
        cout << "\nNode tidak ditemukan" << endl;
        return;
    }
    cout << "\nData Node: " << Node->data << endl;
}

void find(Pohon *Node)
{
    if (isEmpty())
    {
        cout << "\nPohon belum dibuat" << endl;
        return;
    }
    if (!Node)
    {
        cout << "\nNode tidak ditemukan" << endl;
        return;
    }
    cout << "\nNode " << Node->data << " ditemukan" << endl;
    cout << "Root " << root->data << endl;
    cout << "Parent " << (Node->parent ? Node->parent->data : '(Tidak punya Parent)') << endl;

    if (Node->parent)
    {
        if (Node->parent->left == Node && Node->parent->right)
            cout << "Sibling: " << Node->parent->right->data << endl;
        else if (Node->parent->right == Node && Node->parent->left)
            cout << "Sibling: " << Node->parent->left->data << endl;
        else
            cout << "Sibling: (Tidak punya Sibling)" << endl;
    }
}

int main()
{
    init();
    buatNode('A');
    Pohon *NodeB = insertLeft('B', root);
    Pohon *NodeC = insertRight('C', root);
    insertLeft('D', NodeB);
    insertRight('E', NodeB);
    insertLeft('F', NodeC);
    insertRight('G', NodeC);

    cout << "\n== Pemangilan retrieve";
    retrieve(root);
    retrieve(NodeB);
    retrieve(NodeC);

    cout << "\n== Pemangilan find (Node B)";
    find(NodeB);

    cout << "\n== Pemangilan find (Node C)";
    find(NodeC);

    cout << "\n== Pemangilan Update (Mengubah Node B menjadi Z)";
    update('Z', NodeB);

    cout << "\n== Pemanggilan setelah update";
    retrieve(NodeB);

    return 0;
}
