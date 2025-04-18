#include <bits/stdc++.h>
using namespace std;
#define fr(T, s, e, it) for(T i=s; i<e; i+=it)

/**
 * Inorder: Left Root Right
 * Preorder: Root Left Right
 * Postorder: Left Right Root
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

vector<vector<int>> vertical(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // (x, y, value); multiset - if same value
    vector<vector<int>> v;
    if (!root) return v;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        if (node->left) todo.push({node->left, {x-1, y+1}});
        if (node->right) todo.push({node->right, {x+1, y+1}});
    }
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        v.push_back(col);
    }
    return v;
}

signed main() {
    TreeNode* root = buildTree();
    vector<vector<int>> v = vertical(root);
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
    }
    return 0;
}