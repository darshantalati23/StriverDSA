#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl

/*
    4
  3   7
 2   5   9
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

vector<int> inorder(TreeNode* root) {
    vector<int> v;
    if (!root) return v;
    stack<TreeNode*> st;

    TreeNode* node = root;
    while (true) {
        if (node) {
            st.push(node);
            node=node->left;
        } else {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            v.push_back(node->data);
            node=node->right;
        }
    }

    return v;
}

signed main() {
    TreeNode* root = buildTree();
    in(int, k);
    vector<int> v = inorder(root);
    bool flag=true;
    for (int i=1; i<v.size(); i++) {
        if (v[i-1]>=v[i]) {
            flag=false;
            break;
        }
    }
    if (flag)
        cout << "Valid BST" << endl;
    else
        cout << "Not Valid BST" << endl;
    return 0;
}