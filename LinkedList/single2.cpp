#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    if (!head) {
        cout<<"NULL"<<endl;
        return;
    }
    // cout << " | " << head->data << ", " << head->next << " | " << endl;
    cout << head->data << " -> ";
    printList(head->next);
}

int main() {
    int n, num;
    cin>>n>>num;
    
    Node* head = new Node(num);
    Node* temp = head;


    for (int i=1; i<n; i++) {
        cin>>num;
        temp->next = new Node(num);
        temp=temp->next;
    }

    printList(head);

    return 0;
}
