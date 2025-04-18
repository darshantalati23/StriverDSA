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

class Solution {
public:
vector<int> v;
    vector<int> rightSideView(TreeNode* root) {
        rsv(root, 0);
        return v;
    }
    void rsv(TreeNode* root, int level) {
        if (!root) return;
        if (level==v.size())
            v.push_back(root->data);
        rsv(root->right, level+1);
        rsv(root->left, level+1);
    }
vector<int> v2;
    vector<int> leftSideView(TreeNode* root) {
        lsv(root, 0);
        return v2;
    }
    void lsv(TreeNode* root, int level) {
        if (!root) return;
        if (level==v2.size())
            v2.push_back(root->data);
        lsv(root->left, level+1);
        lsv(root->right, level+1);
    }
};

signed main() {
    TreeNode* root = buildTree();
    Solution s;
    vector<int> v = s.rightSideView(root);
    cout << "Right Side View: ";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = s.leftSideView(root);
    cout << "Left Side View: ";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}