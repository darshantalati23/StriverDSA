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

void allTrav(TreeNode* root) {
    if(!root) return;

    stack<pair<TreeNode*, int>> st;
    vector<int> in, pre, post;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second==1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (!it.first->left)
                st.push({it.first->left, 1});
        } else if (it.second==2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (!it.first->left)
                st.push({it.first->right, 1});
        } else {
            post.push_back(it.first->data);
        }
    }
    
    cout << "Preorder: ";
    for (auto it : pre) {
        cout << it << " ";
    }
    cout << endl << "Inorder: ";
    for (auto it : in) {
        cout << it << " ";
    }
    cout << endl << "Postorder: ";
    for (auto it : post) {
        cout << it << " ";
    }
    cout << endl;
}

signed main() {
    TreeNode* root = buildTree();
    allTrav(root);
    return 0;
}