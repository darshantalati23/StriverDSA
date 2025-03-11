#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n) : data(n), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree() {
    cout << "Enter root value (or -1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << "Enter left child of " << node->data << " (or -1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        cout << "Enter right child of " << node->data << " (or -1 for NULL): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }
    return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    TreeNode* root = buildTree();

    vector<vector<int>> levels = levelOrder(root);
    cout << "Level Order Traversal:\n";
    for (auto& level : levels) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }

    return 0;
}
