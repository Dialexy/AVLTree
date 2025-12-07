#include "AVLTree.h"
#include <iostream>
#include <algorithm>

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::AVLTree(const AVLTree &other) {
    root = copyTree(other.root);
}

AVLTree::~AVLTree() {
    destroyTree(root);
}

AVLTree& AVLTree::operator=(const AVLTree &other) {
    if (this != &other) {
        destroyTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

AVLTree::Node* AVLTree::copyTree(Node* node) {
    if (node == nullptr) return nullptr;

    Node* newNode = new Node(node->key, node->value);
    newNode->height = node->height;

    newNode->left  = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

void AVLTree::destroyTree(Node* node) {
    if (node == nullptr) return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::updateHeight(Node* node) {
    if (node == nullptr) {
        return;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = 1 + std::max(leftHeight, rightHeight);
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* B = y->left;

    y->left = x;
    x->right = B;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* B = x->right;

    x->right = y;
    y->left = B;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLTree::Node* AVLTree::rebalance(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    updateHeight(node);
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (balance < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

AVLTree::Node* AVLTree::insertHelper(Node* node, int key, std::string value) {
    if (node == nullptr) {
        return new Node(key, value);
    }

    if (key < node->key) {
        node->left = insertHelper(node->left, key, value);
    }
    else if (key > node->key) {
        node->right = insertHelper(node->right, key, value);
    }
    else {
        node->value = value;
        return node;
    }

    return rebalance(node);
}

void AVLTree::insert(int key, std::string value) {
    root = insertHelper(root, key, value);
}

AVLTree::Node* AVLTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

AVLTree::Node* AVLTree::removeHelper(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeHelper(node->left, key);
    }
    else if (key > node->key) {
        node->right = removeHelper(node->right, key);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* successor = findMin(node->right);
            node->key = successor->key;
            node->value = successor->value;
            node->right = removeHelper(node->right, successor->key);
        }
    }

    return rebalance(node);
}

void AVLTree::remove(int key) {
    root = removeHelper(root, key);
}

std::string* AVLTree::findHelper(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key == node->key) {
        return &(node->value);
    }
    else if (key < node->key) {
        return findHelper(node->left, key);
    }
    else {
        return findHelper(node->right, key);
    }
}

std::string* AVLTree::find(int key) {
    return findHelper(root, key);
}

int AVLTree::height() {
    return getHeight(root);
}

void AVLTree::printInOrderHelper(Node* node) {
    if (node == nullptr) {
        return;
    }

    printInOrderHelper(node->left);
    std::cout << node->key << ": " << node->value << std::endl;
    printInOrderHelper(node->right);
}

void AVLTree::printInOrder() {
    printInOrderHelper(root);
    std::cout << std::endl;
}



