#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x;

/*
    4
  3   7
 2   5 9

Ex: insert 6
    4
  3     7
 2    5   9
       6
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

void printTree(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    bool hasNonNull = true;  // To know when to stop (all NULLs in the last level)

    while (!q.empty() && hasNonNull) {
        int levelSize = q.size();
        hasNonNull = false;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                cout << cur->data << " ";
                q.push(cur->left);
                q.push(cur->right);

                if (cur->left || cur->right)
                    hasNonNull = true;
            } else {
                std::cout << -1 << " ";
                q.push(nullptr);  // Still add children as nulls to maintain structure
                q.push(nullptr);
            }
        }

        cout<<endl;
    }
}


TreeNode* insr(TreeNode* root, int val) {
    TreeNode* cpy = root;
    if (!root) {
        root = new TreeNode(val);
        return root;
    }
    while (root) {
        if (val<root->data) {
            if (root->left)
                root=root->left;
            else {
                root->left = new TreeNode(val);
                break;
            }
        }
        else {
            if (root->right)
                root=root->right;
            else {
                root->right = new TreeNode(val);
                break;
            }
        }
    }
    return cpy;
}

signed main() {
    TreeNode* root = buildTree();
    in(int , val);
    root = insr(root, val);
    printTree(root);
    return 0;
}