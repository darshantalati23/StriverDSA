/*
* AVL TREE IMPLEMENTATION IN C++
* 
* An AVL tree is a self-balancing binary search tree where the difference 
* between heights of left and right subtrees cannot be more than 1 for any node.
* 
* Key Properties:
* - Self-balancing: maintains O(log n) height even after insertions and deletions
* - Balance factor = height(left subtree) - height(right subtree)
* - Every node must have balance factor in {-1, 0, 1}
* - Maintains BST property: left < node < right
* 
* Time Complexity:
* - Search: O(log n)
* - Insert: O(log n)
* - Delete: O(log n)
* - Find min/max: O(log n)
* 
* Space Complexity:
* - Storage: O(n)
* - Auxiliary (for operations): O(log n) for recursion stack
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// AVL Tree Node
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height; // Height of the node in the tree

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    // Get height of a node (nullptr nodes have height 0)
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Calculate balance factor of a node
    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Update height of a node based on its children's heights
    void updateHeight(Node* node) {
        if (node == nullptr)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    /*
    * RIGHT ROTATION
    * 
    * Used when the left subtree of a node becomes too heavy (balance factor > 1)
    * 
    *     y                               x
    *    / \                             / \
    *   x   T3      Right Rotate(y)    T1   y
    *  / \          - - - - - - - ->       / \
    * T1  T2                              T2  T3
    */
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        // Return new root
        return x;
    }

    /*
    * LEFT ROTATION
    * 
    * Used when the right subtree of a node becomes too heavy (balance factor < -1)
    * 
    *     x                               y
    *    / \                             / \
    *   T1  y      Left Rotate(x)       x   T3
    *      / \     - - - - - - - ->    / \
    *     T2  T3                      T1  T2
    */
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        // Return new root
        return y;
    }

    // Recursive function to insert a key in the subtree rooted with node
    // Returns the new root of the subtree
    Node* insert(Node* node, int key) {
        // 1. Perform standard BST insertion
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Duplicate keys not allowed
            return node;

        // 2. Update height of this ancestor node
        updateHeight(node);

        // 3. Get the balance factor to check if this node became unbalanced
        int balance = getBalanceFactor(node);

        // 4. If unbalanced, there are 4 cases to consider:

        // Left Left Case
        /*
        * If balance > 1 and key < node->left->key
        *         z                                      y 
        *        / \                                   /   \
        *       y   T4      Right Rotate (z)          x      z
        *      / \          - - - - - - - - ->      /  \    /  \ 
        *     x   T3                               T1  T2  T3  T4
        *    / \
        *  T1   T2
        */
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        /*
        * If balance < -1 and key > node->right->key
        *     z                                y
        *    / \                             /   \ 
        *   T1  y     Left Rotate(z)        z      x
        *      / \    - - - - - - - ->    / \    / \
        *     T2  x                      T1  T2 T3  T4
        *        / \
        *      T3  T4
        */
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        /*
        * If balance > 1 and key > node->left->key
        *      z                               z                           x
        *     / \                            /   \                        /  \ 
        *    y   T4  Left Rotate(y)        x    T4  Right Rotate(z)    y      z
        *   / \      - - - - - - - - ->  /  \       - - - - - - - ->  / \    / \
        * T1   x                        y    T3                      T1  T2 T3  T4
        *     / \                      / \
        *   T2   T3                  T1   T2
        */
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        /*
        * If balance < -1 and key < node->right->key
        *    z                            z                            x
        *   / \                          / \                          /  \ 
        * T1   y   Right Rotate(y)    T1   x      Left Rotate(z)   z      y
        *     / \  - - - - - - - - ->     / \     - - - - - - - -> / \    / \
        *    x   T4                      T2  y                    T1  T2 T3  T4
        *   / \                             / \
        * T2   T3                          T3  T4
        */
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Find the node with minimum value in a subtree
    Node* findMinValueNode(Node* node) {
        Node* current = node;

        // Loop down to find the leftmost leaf
        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Recursive function to delete a key from the subtree rooted with node
    // Returns the new root of the subtree
    Node* deleteNode(Node* root, int key) {
        // 1. Perform standard BST delete
        if (root == nullptr)
            return root;

        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        if (key < root->key)
            root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        // If key is same as root's key, then this is the node to be deleted
        else {
            // Node with only one child or no child
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                // No child case
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else // One child case
                    *root = *temp; // Copy the contents of the non-empty child

                delete temp;
            } else {
                // Node with two children: Get the inorder successor (smallest
                // in the right subtree)
                Node* temp = findMinValueNode(root->right);

                // Copy the inorder successor's data to this node
                root->key = temp->key;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // If the tree had only one node then return
        if (root == nullptr)
            return root;

        // 2. Update height of the current node
        updateHeight(root);

        // 3. Get the balance factor to check if this node became unbalanced
        int balance = getBalanceFactor(root);

        // 4. If unbalanced, there are 4 cases (same as in insert)

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Recursive function to search a key in the subtree rooted with node
    Node* search(Node* root, int key) {
        // Base case: root is null or the key is at root
        if (root == nullptr || root->key == key)
            return root;

        // Key is greater than root's key
        if (root->key < key)
            return search(root->right, key);

        // Key is smaller than root's key
        return search(root->left, key);
    }

    // Helper function to print the tree in pre-order
    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Helper function to print the tree in-order
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

    // Helper function to print the tree structure
    void printTree(Node* root, string indent, bool last) {
        if (root != nullptr) {
            cout << indent;
            if (last) {
                cout << "└─";
                indent += "  ";
            } else {
                cout << "├─";
                indent += "| ";
            }

            cout << root->key << " (h:" << root->height << ", bf:" << getBalanceFactor(root) << ")" << endl;

            printTree(root->left, indent, root->right == nullptr);
            printTree(root->right, indent, true);
        }
    }

    // Helper function to deallocate memory
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        destroyTree(root);
    }

    // Wrapper functions for the private recursive functions
    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool contains(int key) {
        return search(root, key) != nullptr;
    }

    void printPreOrder() {
        cout << "Pre-order traversal: ";
        preOrder(root);
        cout << endl;
    }

    void printInOrder() {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    void printTreeStructure() {
        cout << "Tree structure:" << endl;
        printTree(root, "", true);
    }
};

/*
* DEMONSTRATION
* 
* This example shows:
* 1. Building an AVL tree with insertions
* 2. The tree structure with heights and balance factors
* 3. Several rotations that occur during insertions
* 4. Deletion and searching operations
*/
int main() {
    AVLTree avl;
    
    // Insert nodes - observe how the tree rebalances
    cout << "Inserting elements: 10, 20, 30, 40, 50, 25" << endl;
    
    cout << "\nAfter inserting 10:" << endl;
    avl.insert(10);
    avl.printTreeStructure();
    
    cout << "\nAfter inserting 20:" << endl;
    avl.insert(20);
    avl.printTreeStructure();
    
    cout << "\nAfter inserting 30 (triggers left rotation):" << endl;
    avl.insert(30);
    avl.printTreeStructure();
    
    cout << "\nAfter inserting 40:" << endl;
    avl.insert(40);
    avl.printTreeStructure();
    
    cout << "\nAfter inserting 50:" << endl;
    avl.insert(50);
    avl.printTreeStructure();
    
    cout << "\nAfter inserting 25 (triggers right-left rotation):" << endl;
    avl.insert(25);
    avl.printTreeStructure();
    
    // Print traversals
    avl.printInOrder();
    avl.printPreOrder();
    
    // Search test
    int searchKey = 25;
    cout << "\nSearching for key " << searchKey << ": " 
        << (avl.contains(searchKey) ? "Found" : "Not Found") << endl;
    
    searchKey = 35;
    cout << "Searching for key " << searchKey << ": " 
        << (avl.contains(searchKey) ? "Found" : "Not Found") << endl;
    
    // Delete test
    int deleteKey = 30;
    cout << "\nDeleting key " << deleteKey << endl;
    avl.remove(deleteKey);
    avl.printTreeStructure();
    avl.printInOrder();
    
    return 0;
}

/*
* AVL vs. REGULAR BST COMPARISON
* 
* Operation | Regular BST (worst) | AVL Tree
* ----------|---------------------|----------
* Search    | O(n)                | O(log n)
* Insert    | O(n)                | O(log n)
* Delete    | O(n)                | O(log n)
* 
* Regular BST advantages:
* - Simpler implementation
* - Less overhead per node (no height info)
* - Faster insertions/deletions when balancing isn't needed
* 
* AVL Tree advantages:
* - Guaranteed O(log n) operations
* - Better for lookup-intensive applications
* - Predictable performance regardless of input order
* 
* When to use AVL Tree:
* - When search operations are frequent
* - When you need worst-case guarantees
* - When the data might arrive in a nearly sorted order
*/