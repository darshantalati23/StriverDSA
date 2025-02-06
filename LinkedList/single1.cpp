#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to create a linked list
Node* createLinkedList(vector<int> &arr, int n, int index = 0) {
    if (index == n) return nullptr; // Base case
    Node* newNode = new Node(arr[index]);
    newNode->next = createLinkedList(arr, n, index + 1); // Recursive call
    return newNode;
}

// Recursive function to print the linked list
void printList(Node* head) {
    if (!head) return; // Base case
    cout << head->data << " -> ";
    printList(head->next);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n=arr.size();

    Node* head = createLinkedList(arr, n); // Creating linked list
    printList(head);
    cout << "NULL\n";

    return 0;
}
