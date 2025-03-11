#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define node TreeNode

struct TreeNode {
    int data;
    node* left;
    node* right;
    node(int n): data(n), left(nullptr), right(nullptr) {}
};

int main() {
    // Creating individual nodes
    int num;
    cin>>num;
    TreeNode* root = new TreeNode(num);
    cin>>num;
    TreeNode* leftChild = new TreeNode(num);
    cin>>num;
    TreeNode* rightChild = new TreeNode(num);
    cin>>num;
    TreeNode* leftleftChild = new TreeNode(num);

    // Connecting the nodes to form the tree
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftleftChild;

    // Example: Accessing node data
    cout << "Root data: " << root->data << endl;
    cout << "Left child data: " << leftChild->data << endl;
    cout << "Right child data: " << rightChild->data << endl;
    cout << "Left left child data: " << leftleftChild->data << endl;
}