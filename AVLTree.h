#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>

class AVLTree {
private:
    struct Node {
        int key;
        std::string value;
        int height;
        Node* left;
        Node* right;

        Node(int k, std::string v) {
            key = k;
            value = v;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rebalance(Node* node);
    Node* insertHelper(Node* node, int key, std::string value);
    Node* removeHelper(Node* node, int key);
    Node* findMin(Node* node);
    std::string* findHelper(Node* node, int key);
    void destroyTree(Node* node);
    Node* copyTree(Node* node);
    void printInOrderHelper(Node* node);

public:
    AVLTree();
    AVLTree(const AVLTree &other);
    AVLTree &operator=(const AVLTree &other);
    ~AVLTree();
    void insert(int key, std::string value);
    void remove(int key);
    std::string* find(int key);
    int height();
    void printInOrder();
};

#endif
