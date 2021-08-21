#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};
void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
void insert(Node *n, int val){
    Node* temp = new Node();
    while(n->next != NULL)
    n = n->next;
    temp->data = val;
    n->next = temp;
}

void del(Node *n){
    if(n->next == NULL) return;
    while(n->next->next != NULL){
        n = n->next;
    }
    n->next = NULL;
}
void push(Node **ref_node, int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = (*ref_node);
    *ref_node = newNode;
}
void deleteWhole(Node **ref_node){
    Node* current = *ref_node;
    while(current != NULL){
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    *ref_node = NULL;
}
int len_linkedList(Node *ptr){
    if(ptr == NULL) return 0;
    else return 1 + len_linkedList(ptr->next);
}
bool searchEle(Node *ptr, int ele){
    if(ptr == NULL) return false;
    if(ptr->data == ele) return true;
    return false or searchEle(ptr->next, ele);
}
Node* nthNode(Node* ptr, int node){
    while(node > 0 && ptr->next != NULL){
        ptr = ptr->next;
        node--;
    }
    if(!node){
        return ptr;
    }
    else{
        cout << "Node exceeds limit" << endl;
        return NULL;
    }
}
void reverse(Node **refNode){
    Node* curr = *refNode;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *refNode = prev;

}
int main(){
    Node* head;
    Node* second;
    Node* third;
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    printList(head);
    insert(head, 7);
    printList(head);

    // del(head);
    // printList(head);
    // delPost(0, head);
    push(&head, 10);
    printList(head);
    push(&head, 20);
    printList(head);
    // deleteWhole(&head);
    // printList(head);
    cout << "Length of the linked list: " << len_linkedList(head) << endl;
    searchEle(head, 17) ? cout << "Present" : cout << "Not Present"; cout << endl;

    Node* ptr = nthNode(head, 1);
    if(ptr != NULL) cout << "Given node "<< 1 << " has data-> " << ptr->data << endl;

    reverse(&head);
    printList(head);
}