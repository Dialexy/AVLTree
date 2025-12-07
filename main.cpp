#include "AVLTree.h"
#include <iostream>

int main() {
    AVLTree tree;
    
    // Test 1: Basic insertions
    std::cout << "=== Test 1: Insertions ===" << std::endl;
    tree.insert(10, "ten");
    tree.insert(20, "twenty");
    tree.insert(30, "thirty");  // Should trigger left rotation
    tree.insert(15, "fifteen");
    tree.insert(25, "twenty-five");
    tree.printInOrder();
    std::cout << "Height: " << tree.height() << std::endl;
    
    // Test 2: Search
    std::cout << "\n=== Test 2: Search ===" << std::endl;
    std::string* result = tree.find(20);
    if (result) {
        std::cout << "Found 20: " << *result << std::endl;
    }
    
    result = tree.find(999);
    if (!result) {
        std::cout << "999 not found (correct!)" << std::endl;
    }
    
    // Test 3: Duplicate key (should overwrite)
    std::cout << "\n=== Test 3: Duplicate Key ===" << std::endl;
    tree.insert(20, "UPDATED-twenty");
    result = tree.find(20);
    if (result) {
        std::cout << "20 now has value: " << *result << std::endl;
    }
    
    // Test 4: Deletion
    std::cout << "\n=== Test 4: Deletion ===" << std::endl;
    tree.remove(20);
    std::cout << "After removing 20:" << std::endl;
    tree.printInOrder();
    
    // Test 5: Copy constructor
    std::cout << "\n=== Test 5: Copy Constructor ===" << std::endl;
    AVLTree treeCopy = tree;
    std::cout << "Original tree:" << std::endl;
    tree.printInOrder();
    std::cout << "Copied tree:" << std::endl;
    treeCopy.printInOrder();
    
    // Test 6: Assignment operator
    std::cout << "\n=== Test 6: Assignment Operator ===" << std::endl;
    AVLTree tree2;
    tree2.insert(100, "hundred");
    tree2 = tree;
    std::cout << "After assignment:" << std::endl;
    tree2.printInOrder();
    
    return 0;
}
