#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    void insertNode(int data)
    {
        this->data = data;
    }
};

class BST 
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }
};

Node* minimum(BST* t, Node* x) 
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

void insert(BST* t, Node* n) 
{
    Node* y = NULL;
    Node* temp = t->root;
    while (temp != NULL) {
        y = temp;
        if (n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    n->parent = y;

    if (y == NULL)
    {
        t->root = n;
        
    }
    else if (n->data < y->data)
        y->left = n;
    else
        y->right = n;
}

void transplant(BST* t, Node* u, Node* v) 
{
    if (u->parent == NULL) 
        t->root = v;
    else if (u == u->parent->left) 
        u->parent->left = v;
    else 
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

void delete_Node(BST* t, Node* z) 
{
    if (z->left == NULL)
    {
        transplant(t, z, z->right); 
        free(z);
    }
    else if (z->right == NULL) 
    {
        transplant(t, z, z->left);
        free(z);
    }
    else 
    {
        Node* y = minimum(t, z->right); 
        if (y->parent != z) 
        {
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        free(z);
    }
}

void inorderRec(Node* root)
{
    if (root != NULL) {
        inorderRec(root->left);
        cout << root->data << "-->";
        inorderRec(root->right);
    }
}

int main() 
{
    BST* t = new BST();

    
    
    Node* a, * b, * c, * d, * e, * f, * g, * h, * i, * j, * k, * l, * m;

    a = new Node(10); 
    b = new Node(20);
    c = new Node(5);
    d = new Node(100);
    e = new Node(90);
    f = new Node(40);
    g = new Node(50);
    h = new Node(60);
    i = new Node(70);
    j = new Node(80);
    k = new Node(150);
    l = new Node(110);
    m = new Node(120); 

    insert(t, a);  
    insert(t, b); 
    insert(t, c); 
    insert(t, d);
    insert(t, e);
    insert(t, f);
    insert(t, g);
    insert(t, h);
    insert(t, i);
    insert(t, j);
    insert(t, k);
    insert(t, l);
    insert(t, m); 

    cout << endl << "All the value inserted (Inorder preview): ";
    inorderRec(t->root);
   
    delete_Node(t, c);
    delete_Node(t, m);


    cout << endl << "Remaining values after deletion (Inorder preview): ";
    inorderRec(t->root);

    return 0;
}