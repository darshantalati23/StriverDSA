#include <bits/stdc++.h>
using namespace std;

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

// Method 1
/*vector<int> bottomView(TreeNode* root) {
    map<int, int> bottomNode;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, x] = q.front(); q.pop();

        // overwrite every time (latest at this x is bottom-most)
        bottomNode[x] = node->data;

        if (node->left)  q.push({node->left, x - 1});
        if (node->right) q.push({node->right, x + 1});
    }

    vector<int> ans;
    for (auto& [x, val] : bottomNode)
        ans.push_back(val);
    return ans;
}*/

// Method 2
vector<int> bottomView(TreeNode* root) {
    vector<int> v;
    if (!root) return v;
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        mpp[line] = node->data; // We removed the 'if' condition from the topView
        if (node->left) q.push({node->left, line-1});
        if (node->right) q.push({node->right, line+1});
    }
    for (auto it : mpp) {
        v.push_back(it.second);
    }
    return v;
}

signed main() {
    TreeNode* root = buildTree();
    vector<int> v = bottomView(root);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}