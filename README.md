# AVL Tree in C++

A complete implementation of a self-balancing AVL (Adelson-Velsky and Landis) tree in C++. This data structure maintains O(log n) time complexity for insertions, deletions, and searches by automatically rebalancing itself after modifications.

## Features

- **Self-balancing**: Automatically maintains balance through rotations
- **Generic key-value storage**: Integer keys with string values
- **Complete API**: Insert, remove, find, and height operations
- **Memory safe**: Proper copy constructor, assignment operator, and destructor (Rule of Three)
- **Efficient**: O(log n) time complexity for all major operations

## Project Structure

```
AVL Tree in C++/
├── AVLTree.h          # Header file with class declaration
├── AVLTree.cpp        # Implementation file
├── main.cpp           # Example usage and tests
└── README.md          # This file
```

## How to Compile and Run

### Using g++

```bash
g++ -std=c++11 -o avltree main.cpp AVLTree.cpp
./avltree
```

### Using clang++

```bash
clang++ -std=c++11 -o avltree main.cpp AVLTree.cpp
./avltree
```

### Using CMake (Optional)

Create a `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.10)
project(AVLTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(avltree main.cpp AVLTree.cpp)
```

Then build:

```bash
mkdir build
cd build
cmake ..
make
./avltree
```

## Usage

### Basic Example

```cpp
#include "AVLTree.h"
#include <iostream>

int main() {
    AVLTree tree;

    // Insert key-value pairs
    tree.insert(10, "ten");
    tree.insert(20, "twenty");
    tree.insert(30, "thirty");

    // Search for a key
    std::string* result = tree.find(20);
    if (result) {
        std::cout << "Found: " << *result << std::endl;
    }

    // Remove a key
    tree.remove(20);

    // Print all entries in order
    tree.printInOrder();

    // Get tree height
    std::cout << "Height: " << tree.height() << std::endl;

    return 0;
}
```

## API Reference

### Constructor & Destructor

- `AVLTree()` - Creates an empty AVL tree
- `AVLTree(const AVLTree &other)` - Copy constructor
- `~AVLTree()` - Destructor (automatically cleans up all nodes)

### Operators

- `AVLTree& operator=(const AVLTree &other)` - Assignment operator

### Methods

- `void insert(int key, std::string value)` - Insert or update a key-value pair
- `void remove(int key)` - Remove a key from the tree
- `std::string* find(int key)` - Search for a key, returns pointer to value or nullptr
- `int height()` - Returns the height of the tree
- `void printInOrder()` - Prints all entries in ascending key order

## Integrating into Your Project

### Option 1: Direct Integration

1. Copy `AVLTree.h` and `AVLTree.cpp` into your project directory
2. Include the header in your code: `#include "AVLTree.h"`
3. Compile both files with your project

### Option 2: As a Static Library

Compile as a static library:

```bash
g++ -c -std=c++11 AVLTree.cpp -o AVLTree.o
ar rcs libavltree.a AVLTree.o
```

Then link in your project:

```bash
g++ -std=c++11 your_program.cpp -L. -lavltree -o your_program
```

### Option 3: Template Modification

To use custom types instead of `int` keys and `std::string` values, modify the class to use templates:

```cpp
template<typename K, typename V>
class AVLTree {
    // Modify Node struct and methods accordingly
};
```

## How It Works

### AVL Tree Properties

- A binary search tree where the heights of left and right subtrees differ by at most 1
- Balance factor = height(left subtree) - height(right subtree)
- Valid balance factors: -1, 0, or 1

### Rotations

The tree uses four types of rotations to maintain balance:
- **Left Rotation**: Used when right subtree is too tall
- **Right Rotation**: Used when left subtree is too tall
- **Left-Right Rotation**: Left rotation on left child, then right rotation on node
- **Right-Left Rotation**: Right rotation on right child, then left rotation on node

### Time Complexity

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Insert    | O(log n) | O(log n) |
| Delete    | O(log n) | O(log n) |
| Search    | O(log n) | O(log n) |
| Height    | O(1)     | O(1)     |

### Space Complexity

O(n) where n is the number of nodes in the tree.

## Example Output

Running the included `main.cpp` produces output demonstrating:
- Basic insertions with automatic rebalancing
- Search operations (successful and unsuccessful)
- Duplicate key handling (value updates)
- Deletion with rebalancing
- Copy constructor functionality
- Assignment operator functionality

## Requirements

- C++11 or later
- Standard C++ compiler (g++, clang++, MSVC, etc.)

## License

This project is provided as-is for educational and commercial use.

## Contributing

Feel free to fork, modify, and use this implementation in your projects. Contributions and improvements are welcome!
