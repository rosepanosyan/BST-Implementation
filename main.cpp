#include <iostream>
#include "bst.h"

int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "InOrder Traversal: ";
    tree.inOrderTraversal();

    std::cout << "PreOrder Traversal: ";
    tree.preOrderTraversal();

    std::cout << "PostOrder Traversal: ";
    tree.postOrderTraversal();

    std::cout << "\nTree contains 40? :" << (tree.search(40) ? "Yes" : "No") << std::endl;
    std::cout << "Tree contains 90? :" << (tree.search(90) ? "Yes" : "No") << std::endl;

    std::cout << "\nMinimum value in tree: " << tree.findMin() << std::endl;
    std::cout << "Maximum value in tree: " << tree.findMax() << std::endl;

    std::cout << "\nSize of tree: " << tree.size() << std::endl;
    std::cout << "Height of tree: " << tree.height() << std::endl;

    std::cout << "\nRemoving 20 (leaf node)...\n";
    tree.remove(20);
    tree.inOrderTraversal();

    std::cout << "Removing 30 (node with one child)...\n";
    tree.remove(30);
    tree.inOrderTraversal();

    std::cout << "Removing 50 (node with two children)...\n";
    tree.remove(50);
    tree.inOrderTraversal();

    std::cout << "\nCreating a copy of the tree...\n";
    BST<int> treeCopy = tree;
    std::cout << "InOrder Traversal of copied tree: ";
    treeCopy.inOrderTraversal();

    std::cout << "\nClearing original tree...\n";
    tree.clear();
    std::cout << "Original tree is " << (tree.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Copied tree is " << (treeCopy.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << "\nTesting move semantics...\n";
    BST<int> treeMoved = std::move(treeCopy);
    std::cout << "After move, copied tree is " << (treeCopy.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Moved tree contents: ";
    treeMoved.inOrderTraversal();

    return 0;
}
