#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x;
/*
    4
  3   7
 2   5 9
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

int floorBST(TreeNode* root, int val) {
    int floor = INT_MIN;
    while (root) {
        if (root->data == val)
            return root->data;
        else if (root->data < val) {
            floor = max(floor, root->data);
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return (floor==INT_MIN?-1:floor);
}

signed main() {
    TreeNode* root = buildTree();
    in(int , val);
    cout << floorBST(root, val) << endl;
    return 0;
}