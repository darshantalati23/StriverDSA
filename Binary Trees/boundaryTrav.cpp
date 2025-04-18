#include <bits/stdc++.h>
using namespace std;
#define fr(T, s, e, it) for(T i=s; i<e; i+=it)

/**
     1
    /  \
   2    3
   \   / \
    4 5   6
   /   \
  7     8

 Boundary Traversal : 1 2 4 7 8 6 3 -> "Anticlock-wise"
 */

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

bool isLeaf(TreeNode* root) {
    if (root->left==root->right&&root->left==nullptr)
        return true;
    return false;
}

void addLeaves(TreeNode* root, vector<int> &v) {
    if (isLeaf(root)) {
        v.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, v);
    if (root->right) addLeaves(root->right, v);
}

void addLeftBoundary(TreeNode* root, vector<int> &v) {
    TreeNode* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) v.push_back(cur->data);
        if (cur->left) cur=cur->left;
        else cur->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int> &v) {
    TreeNode* cur = root->right;
    stack<int> st;
    while (cur) {
        if (!isLeaf(cur)) st.push(cur->data);
        if (cur->right) cur=cur->right;
        else cur->left;
    }
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
}

vector<int> boundary(TreeNode* root) {
    vector<int> v;
    if (!root) return v;
    if (!isLeaf(root)) v.push_back(root->data);
    addLeftBoundary(root, v);
    addLeaves(root, v);
    addRightBoundary(root, v);
    return v;   
}

signed main() {
    TreeNode* root = buildTree();
    vector<int> v = boundary(root);
    for (auto it : v) cout << it << " ";
    return 0;
}