#ifndef BST_H
#define BST_H

#include <cstddef>

template<typename T>
class BST{
private:
    struct Node{
        T data;
        Node* left;
        Node* right;

        Node() : data(0), left(nullptr), right(nullptr) {}
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {} 
    };

    Node* root;
private:
    Node* copyTree(Node* otherNode);
    void destroyTree(Node* node);

public:
    BST();
    BST(const T& val);
    BST(const BST<T>& other);
    BST(BST<T>&& other);
    BST<T>& operator=(const BST<T>& other);
    BST<T>& operator=(BST<T>&& other);

    ~BST();

    void insert(const T& data);
    Node* insertHelper(Node* node, const T& data);
    void remove(const T& data);
    Node* removeHelper(Node* node, const T& data);
    bool search(const T& data) const;
    bool searchHelper(Node* node, const T& data) const;
    bool isEmpty() const;

    void preOrderTraversal() const;
    void preOrder(Node* node) const;
    void inOrderTraversal() const;
    void inOrder(Node* node) const;
    void postOrderTraversal() const;
    void postOrder(Node* node) const;

    const T& findMax() const;
    const T& findMaxHelper(Node* node) const;
    const T& findMin() const;
    const T& findMinHelper(Node* node) const;
    void clear();
    void clearHelper(Node* node);
    size_t size() const;
    size_t sizeHelper(Node* node) const;
    size_t height() const;
    size_t heightHelper(Node* node) const;
};

#include "bst.cpp"

#endif 