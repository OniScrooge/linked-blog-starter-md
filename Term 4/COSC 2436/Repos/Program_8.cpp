/*
Name: Patrick Ignaut W211197397

Date: 11/30/24

Explanation: The program implements the simple binary tree outlined in the problem. It includes the member functions insert, search(double), inorder, search(double, node), size,
leafCount, height, and width. The driver program creates a binary tree and inserts several values. It attempts to use the search on two values, one that exists and one that doesn't.
It then checks the order status of the tree. After which is lists the size, count, height, and width of the tree. Finally it tests the copy constructor and the operators.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class BTree {
private:
    struct BTreeNode {
        double data;
        BTreeNode *left, *right;
        BTreeNode(double x) : data(x), left(nullptr), right(nullptr) {}
    };

    BTreeNode* root;

    // Recursive helper for search
    bool search(double x, BTreeNode* t) const {
        if (!t) return false;
        if (t->data == x) return true;
        if (x < t->data) return search(x, t->left);
        return search(x, t->right);
    }

    // Recursive helper for in-order traversal
    void inorder(BTreeNode* t, vector<double>& v) const {
        if (!t) return;
        inorder(t->left, v);
        v.push_back(t->data);
        inorder(t->right, v);
    }

    // Recursive helper for size
    int size(BTreeNode* t) const {
        if (!t) return 0;
        return 1 + size(t->left) + size(t->right);
    }

    // Recursive helper for leaf count
    int leafCount(BTreeNode* t) const {
        if (!t) return 0;
        if (!t->left && !t->right) return 1;
        return leafCount(t->left) + leafCount(t->right);
    }

    // Recursive helper for height
    int height(BTreeNode* t) const {
        if (!t) return 0;
        return 1 + max(height(t->left), height(t->right));
    }

    // Helper for width
    int width(BTreeNode* t) const {
        if (!t) return 0;
        queue<BTreeNode*> q;
        q.push(t);
        int maxWidth = 0;
        while (!q.empty()) {
            int count = q.size();
            maxWidth = max(maxWidth, count);
            while (count--) {
                BTreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return maxWidth;
    }

    // Recursive helper for deep copy
    BTreeNode* copy(BTreeNode* t) const {
        if (!t) return nullptr;
        BTreeNode* newNode = new BTreeNode(t->data);
        newNode->left = copy(t->left);
        newNode->right = copy(t->right);
        return newNode;
    }

    // Recursive helper for cleanup
    void clear(BTreeNode* t) {
        if (!t) return;
        clear(t->left);
        clear(t->right);
        delete t;
    }

public:
    // Constructor
    BTree() : root(nullptr) {}

    // Copy constructor
    BTree(const BTree& other) : root(copy(other.root)) {}

    // Assignment operator
    BTree& operator=(const BTree& other) {
        if (this == &other) return *this;
        clear(root);
        root = copy(other.root);
        return *this;
    }

    // Destructor
    ~BTree() { clear(root); }

    // Insert without recursion
    void insert(double x) {
        BTreeNode* newNode = new BTreeNode(x);
        if (!root) {
            root = newNode;
            return;
        }
        BTreeNode* t = root;
        while (true) {
            if (x < t->data) {
                if (!t->left) {
                    t->left = newNode;
                    break;
                }
                t = t->left;
            } else {
                if (!t->right) {
                    t->right = newNode;
                    break;
                }
                t = t->right;
            }
        }
    }

    // Search
    bool search(double x) const { return search(x, root); }

    // In-order traversal
    void inorder(vector<double>& v) const { inorder(root, v); }

    // Size
    int size() const { return size(root); }

    // Leaf count
    int leafCount() const { return leafCount(root); }

    // Height
    int height() const { return height(root); }

    // Width
    int width() const { return width(root); }
};

// Driver program
int main() {
    BTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;

    vector<double> v;
    tree.inorder(v);
    cout << "Inorder Traversal: ";
    for (double x : v) cout << x << " ";
    cout << endl;

    cout << "Size: " << tree.size() << endl;
    cout << "Leaf Count: " << tree.leafCount() << endl;
    cout << "Height: " << tree.height() << endl;
    cout << "Width: " << tree.width() << endl;

    // Demonstrate copy constructor
    BTree treeCopy = tree;
    v.clear();
    treeCopy.inorder(v);
    cout << "Inorder Traversal of Copy: ";
    for (double x : v) cout << x << " ";
    cout << endl;

    // Demonstrate assignment operator
    BTree anotherTree;
    anotherTree = tree;
    v.clear();
    anotherTree.inorder(v);
    cout << "Inorder Traversal of Assigned Tree: ";
    for (double x : v) cout << x << " ";
    cout << endl;

    return 0;
}