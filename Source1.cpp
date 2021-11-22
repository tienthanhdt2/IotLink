#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int);
    ~Node();
};
//Khởi tạo node
Node::Node() {
    data = 0;
    left = nullptr;
    right = nullptr;
}
//
Node::Node(int x) {
    data = x;
    left = nullptr;
    right = nullptr;
}
Node::~Node() {}

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = NULL;
    }
    Node* insertNode(Node*, int);
    Node* deleteNode(Node*, int);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    Node* findMinimum(Node*);
    Node* searchElement(Node*, int);


    Node* getRoot() {
        return root;
    }

    void setRoot(Node* ptr) {
        root = ptr;
    }
};


/* Tim phan tu nho nhat  */
Node* BinaryTree::findMinimum(Node* rootPtr) {
    while (rootPtr->left != NULL) {
        rootPtr = rootPtr->left;
    }
    return rootPtr;
}

/* Ham chen node */
Node* BinaryTree::insertNode(Node* rootPtr, int n) {
    if (rootPtr == NULL) {
        Node* p = new Node(n);
        return p;
    }
    if (n < rootPtr->data) {
        rootPtr->left = insertNode(rootPtr->left, n);
    }
    if (n > rootPtr->data) {
        rootPtr->right = insertNode(rootPtr->right, n);
    }
    return rootPtr;
}

/* Ham xoa node */
Node* BinaryTree::deleteNode(Node* rootPtr, int n) {
    if (rootPtr == NULL) {
        cout << "Node to be deleted is not present.!" << endl;
        return rootPtr;
    }
    else if (n < rootPtr->data) {
        rootPtr->left = deleteNode(rootPtr->left, n);
    }
    else if (n > rootPtr->data) {
        rootPtr->right = deleteNode(rootPtr->right, n);
    }
    else {
        if (rootPtr->left == NULL && rootPtr->right == NULL) {
            delete rootPtr;
            rootPtr = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }
        else if (rootPtr->right == NULL) {
            Node* temp = rootPtr;
            rootPtr = rootPtr->left;
            delete temp;
        }
        else {
            Node* temp = findMinimum(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->left = deleteNode(rootPtr->right, temp->data);
        }
    }

    return rootPtr;
}
Node* BinaryTree::searchElement(Node* node, int data) {
    if (node != nullptr) {
        if (data > node->data) return searchElement(node->right, data);
        else if (data < node->data) return searchElement(node->left, data);
        else {
            cout << "Da tim thay";
            return node;
        }
    }
    return nullptr;
}
/* In ra cay  */
void BinaryTree::inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}

void BinaryTree::preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree::postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
}

int main()
{
    BinaryTree l1;
    int ch, ele, res;
    Node* ptr;
    do
    {
        cout << "1 - Insert n";
        cout << "2 - PRINT(LNR) ";
        cout << "3 - PRINT(NLR";
        cout << "4 - PRINT(LRN) ";
        cout << "5 - DELETE";
        cout << "6- Shearch";
        cout << "Enter choice\n";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Nhap phan tu vao cay\n";
            cin >> ele;

            ptr = l1.insertNode(l1.getRoot(), ele);

            l1.setRoot(ptr);
            break;
        case 2:
            cout << "In cay theo LNR" << endl;
            l1.inOrder(l1.getRoot());
            cout << endl;
            break;
        case 3:
            cout << "In cay theo NLR" << endl;
            l1.preOrder(l1.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "In cay theo LRN" << endl;
            l1.postOrder(l1.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "Nhap phan tu can xoa trong cay" << endl;
            cin >> ele;
            ptr = l1.deleteNode(l1.getRoot(), ele);
            l1.setRoot(ptr);
        case 6: {
            cout << "Nhap gia tri can tim: ";
            int ele; cin >> ele;
            l1.searchElement(l1.getRoot(), ele);
            cout << endl;
            system("pause");
            break; }

        default: cout << "Lua chon khong hop le" << endl;
        }
        }
        while (ch >= 1 && ch <= 6);
        return 0;
    }
