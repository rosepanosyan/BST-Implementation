#include "bst.h"
using namespace std;

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::BST(const T& val) {
    root = new Node(val);
}

template<typename T>
BST<T>::BST(const BST<T>& other) {
    root = copyTree(other.root);
}

template<typename T>
BST<T>::BST(BST<T>&& other) {
    root = other.root;
    other.root = nullptr;
}

template<typename T>
BST<T>& BST<T>::operator=(const BST<T>& other) {
    if(this == &other) {
        return *this;
    }
    destroyTree(root);
    root = copyTree(other.root);

    return *this;
}

template<typename T>
BST<T>& BST<T>::operator=(BST<T>&& other) {
    if(this == &other) {
        return *this;
    }
    destroyTree(root);
    root = other.root;
    other.root = nullptr;

    return *this;
}

template<typename T>
typename BST<T>::Node* BST<T>::copyTree(typename BST<T>::Node* otherNode) {
    if(!otherNode) return nullptr;
    Node* newNode = new Node(otherNode->data);
    newNode->left = copyTree(otherNode->left);
    newNode->right = copyTree(otherNode->right);
    return newNode;
}

template<typename T>
void BST<T>::destroyTree(typename BST<T>::Node* node) {
    if(!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template<typename T>
BST<T>:: ~BST() {
    destroyTree(root);
}

template<typename T>
void BST<T>::insert(const T& data) {
    root = insertHelper(root, data);
}

template<typename T>
typename BST<T>::Node* BST<T>::insertHelper(typename BST<T>::Node* node, const T& data) {
    if(!node) {
        return new Node(data);
    }
    if(data < node->data) {
        node->left = insertHelper(node->left, data);
    }else if(data > node->data) {
        node->right = insertHelper(node->right, data);
    }
    return node;
}


template<typename T>
void BST<T>::remove(const T& data) {
    root = removeHelper(root, data);
}


template<typename T>
typename BST<T>::Node* BST<T>::removeHelper(typename BST<T>::Node* node, const T& data) {
    if(!node) return nullptr;
    if(data < node->data) {
        node->left = removeHelper(node->left, data);
    }else if(data > node->data) {
        node->right = removeHelper(node->right, data);
    }else {
       if(!node->left && !node->right) {
            delete node;
            return nullptr;
       }else if(!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
       }else if(!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
       }else {
            const T& successor = findMinHelper(node->right);
            node->data = successor;
            node->right = removeHelper(node->right, successor);
       }
    }
    return node;
}

template<typename T>
bool BST<T>::search(const T& data) const{
    return searchHelper(root, data);
}

template<typename T>
bool BST<T>::searchHelper(Node* node, const T& data) const {
    if(!node) return false;

    if(node->data == data) {
        return true;
    }else if(node->data > data) {
        return searchHelper(node->left, data);
    }else {
        return searchHelper(node->right, data);
    }
}

template<typename T>
bool BST<T>::isEmpty() const {
    return !root;
}

template<typename T>
void BST<T>::preOrderTraversal() const{
    preOrder(root);
    cout << endl;
}

template<typename T>
void BST<T>::preOrder(Node* node) const {
    if(!node) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void BST<T>::inOrderTraversal() const {
    inOrder(root);
    cout << endl;
}

template<typename T>
void BST<T>::inOrder(Node* node) const {
    if(!node) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}


template<typename T>
void BST<T>::postOrderTraversal() const {
    postOrder(root);
    cout << endl;
}

template<typename T>
void BST<T>::postOrder(Node* node) const {
    if(!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}


template<typename T>
const T& BST<T>::findMax() const {
    return findMaxHelper(root);
}

template<typename T>
const T& BST<T>::findMaxHelper(Node* node) const {
    if(!node) {
        throw runtime_error("Cannot find maximum of a null subtree.");
    }
    while(node->right) {
        node = node->right;
    }
    return node->data;
}

template<typename T>
const T& BST<T>::findMin() const {
    return findMinHelper(root);
}

template<typename T>
const T& BST<T>::findMinHelper(Node* node) const {
    if(!node) {
        throw runtime_error("Cannot find maximum of a null subtree.");
    }
    while(node->left) {
        node = node->left;
    }
    return node->data;
}

template<typename T>
void BST<T>::clear() {
    clearHelper(root);
    root = nullptr;
}

template<typename T>
void BST<T>::clearHelper(Node* node) {
    if(!node) return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
} 

template<typename T>
size_t BST<T>::size() const {
    return sizeHelper(root);
}

template<typename T>
size_t BST<T>::sizeHelper(Node* node) const {
    if(!node) return 0;
    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}

template<typename T>
size_t BST<T>::height() const {
    return heightHelper(root);
}

template<typename T>
size_t BST<T>::heightHelper(Node* node) const {
    if(!node) return -1;
    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);

    return 1 + max(leftHeight, rightHeight);
}