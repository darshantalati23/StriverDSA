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

    int ind;
    cin>>ind>>num;
    temp=head;
    /*
    // Logically wrong code below. Head is not updated. Only temp is.
    for (int i=0; i<ind; i++) {
        temp=temp->next;
    }
    Node* newNode = new Node(num);
    newNode->next=temp;
    temp=newNode;
    */

    if (ind == 0) {
        Node* newNode = new Node(num);
        newNode->next = head;
        head = newNode;  // Update head pointer
    } else {
        temp = head;
        for (int i = 0; i < ind - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid index!" << endl;
        } else {
            Node* newNode = new Node(num);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    printList(head);
    return 0;
}
