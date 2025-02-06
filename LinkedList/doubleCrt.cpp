#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void printList(Node* head) {
    if (!head) {
        cout<<"NULL"<<endl;
        return;
    }
    cout << " | " << head->prev << " | " << head->data << " | " << head->next << " | " << endl;
    // cout << head->data << " -> ";
    printList(head->next);
}

int main() {
    int n, num;
    cin>>n>>num;
    
    Node* head = new Node(num);
    Node* temp = head;
    /*
    // Wrong logic of linking below
    Node* prv = head;

    for (int i=1; i<n; i++) {
        cin>>num;
        Node* newNode = new Node(num);
        temp->next=newNode;
        temp->prev=prv;
        prv=temp;
        temp=temp->next;
    }
    */
   for (int i=1; i<n; i++) {
        cin>>num;
        Node* newNode = new Node(num);
        temp->next=newNode;
        newNode->prev=temp;
        temp=temp->next;
    }

    printList(head);
    return 0;
}
