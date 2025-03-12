#include <bits/stdc++.h>
using namespace std;
#define fr(T, s, e, it) for(T i=s; i<e; i+=it)

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n) : data(n), left(nullptr), right(nullptr) {}
};

/*
ENTER ROOT, LEFT AND RIGHT IN RESPECTIVE ORDER. '-1' TO SKIP THAT CHILD/ROOT.
*/
TreeNode* buildTree() {
    // cout << "Enter root value (or -1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // cout << "Enter left child of " << node->data << " (or -1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        // cout << "Enter right child of " << node->data << " (or -1 for NULL): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }
    return root;
}

/**
 * The given code performs an iterative preorder traversal
 * of a binary tree using an explicit stack. It starts by checking
 * if the root is `nullptr`, returning an empty vector if true.
 * A stack is initialized with the root node, and a loop runs while
 * the stack is not empty. In each iteration, the top node is popped,
 * its value is added to the result vector, and its right child (if any)
 * is pushed first, followed by the left child. This ensures that when
 * popping from the stack, the left child is processed before the
 * right child, maintaining the preorder sequence (Node → Left → Right).
 * Unlike a recursive approach that relies on the system call stack,
 * this method manually manages a stack, preventing stack overflow
 * issues in deep trees while maintaining efficient traversal.
 */
vector<int> preOrder(TreeNode* root) {
    vector<int> p;
    if (root == nullptr) return p;

    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        p.push_back(root->data);
        if (root->right != nullptr) {
            st.push(root->right);
        }
        if (root->left != nullptr) {
            st.push(root->left);
        }
    }
    return p;
}

int main() {
    
    TreeNode* root = buildTree();

    vector<int> v = preOrder(root);
    cout << "Level Order Traversal:\n";
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
