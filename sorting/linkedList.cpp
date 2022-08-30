/*
    advantages of linked list over array-
        1. insertion and deletion operation can be done easily
        2. space optimized data structure, only use space corresponding to data available, unlike array left empty
    disadvantages of linked list
        1. search in O(n)
        2. accesing the last element in the list
        3. extra memory for address pointer
        4. Random access is not allowed, so cant do binary search
        5. not cache friendly, so cant be accessed by reference- due to continguous allocation of memory
        modifying an element is faster in arrays
        while inserting/deleting is faster in linked list
    Operations on linked list:
    1. delete a node
        front
        back
        mid
        O(1) both best and worst
    2. insert a node
        front
        mid
        back
        both O(1)
    3. Search a node
        O(n) worst and average

    * For arrays, memory is allocated at compile time, but for linked list, it is done on runtime



*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(int n){
        val = n;
        next = NULL;
    }
};
void printList(Node* node){
    while(node != NULL){
        cout << node->val << " ";
    } cout << endl; 
}
void makeSize10LinkedList(){
    Node* head = new Node(0);
    Node* temp = head;
    for(int i = 1; i <= 5; i++){
        Node* nextNode = new Node(i);
        temp->next = nextNode;
        temp = temp->next;
    }
    temp = head;
    cout << "Elements in linkedList: ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertion(){
    // insert at begining
    Node* head = new Node(0);
    Node* temp = head;
    for(int i = 1; i <= 5; i++){
        Node* nextNode = new Node(i);
        temp->next = nextNode;
        temp = temp->next;
    }
    Node* insertedNode = new Node(5);
    insertedNode->next = head;
    head = insertedNode;
    temp = head;
    cout << "After insertion at beginning: ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // inserting at end
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(11);
    temp->next = newNode;

    cout << "After insertion at end: ";
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // insertion after 2 positions
    int post = 2;
    int totalLength = 0;
    temp = head;
    while(temp != NULL){
        ++totalLength;
        temp = temp->next;
    }
    cout << "Total length of linked List: " << totalLength << endl;

    temp = head;
    Node *temp1 = head, *temp2 = NULL;
    while(post-- > 0){
        temp2 = temp1;
        temp1 = temp1->next;
    }
    Node *newNodeII = new Node(40);
    newNodeII->next = temp1;
    temp2->next = newNodeII;

    cout << "After insertion after 2 positions: ";
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Deletion(){
    Node* head = new Node(0);
    Node* temp = head;
    for(int i = 1; i <= 8; i++){
        Node* nextNode = new Node(i);
        temp->next = nextNode;
        temp = temp->next;
    }
    // Before deleting
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deleting the first node
    temp = head;
    head = head->next;
    delete temp;

    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    //Delete the last node

    temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete the third node
    temp = head;
    int nodeNO = 3;
    while(--nodeNO > 1){
        //stop at second node'
        temp = temp->next;
    }
    //now I need to delete the temp->next
    if(temp->next != NULL){
        //store the nextToNext node
        Node* nextTonext = temp->next->next;
        free(temp->next);
        temp->next = nextTonext;
    }
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    //deleting no equivalent to 6;
    temp = head;
    while(temp->next->val != 6){
        temp = temp->next;
    }
    Node* nextTonext = temp->next->next;
    free(temp->next);
    temp->next = nextTonext;
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteNodeRecursion(Node ** headRef, int key){
    if(*headRef == NULL){
        cout << "Node Not Found!" << endl;
        return;
    }
    Node* recHead = *headRef;
    if(recHead->next != NULL and recHead->next->val == key){
        Node* temp= recHead->next;
        recHead->next = recHead->next->next;
        free(temp);
    } else deleteNodeRecursion(&recHead->next, key);

}
void deleteLinkedList(){
    /*
        In Java, Python, and JavaScript automatic garbage collection happens, 
        so deleting a linked list is easy. Just need to change head to null.

        also, delete can be done in 2 ways. 
            - keep moving to next pointer, and free the previous pointer.
            - keep iterating from back to front, and keep freeing the last node

    */

}
void nthNode(Node** headRef, int n){

    /*
        nth Node from beginning is easy. but from last, we have the following methods:
            - it is length-n+1 th node from beginning
            - or, we can maintain a window of size n, and keep shifting this window by 1 to the right
    */
    Node* low = *headRef;
    Node* high = low;
    while(--n>0 and high->next != NULL){
        high = high->next;
    }
    if(n != 0) {
        cout << "n is greater than the size of linkedList" <<endl;
        return;
    }
    while(high->next != NULL){
        low = low->next;
        high = high->next;
    }
    cout << "Required node from last: " << low->val << endl;
} 
void findMid(Node* head){
    /*
        Can be done in 2 ways
        - find the length of the linked list, then traverse it again upto n/2 length of linked list
        - use two pointer technique.
    */
    if(!head) return;
    Node* slow = head;
    Node* high = head;
    while(high != NULL and high->next != NULL){
        slow = slow->next;
        high = high->next->next;
    }
    cout << "Mid element " << slow->val << endl;
}
bool checkPalindromeLinkedList(Node*& head, Node* end){
    if(!end) return true;
    if(end->next==NULL){
        // Last node is found!
    } else if(!checkPalindromeLinkedList(head, end->next)) return false;
    if(!head) return true;
    cout << head->val << " " << end->val << endl;
    if(head->val == end->val){
        head = head->next;
        return true;
    } return false;
    
}
bool checkPalindromeUsingReverse(Node*& head){
    Node* slow = head, *fast = head;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow;
    cout << mid->val << endl;
    // Reverse the linked List after mid pointer
    // from mid to end
    Node* prev = mid, *next, *current = mid->next, *temp = mid->next;
    mid->next = NULL;
    while(current != NULL and current->next != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // current = temp;
    Node* temphead = head;
    while(temphead != NULL){
        cout << temphead->val << " ";
        temphead = temphead->next;
    } cout << endl;
    temphead = current;
    while(temphead != NULL){
        cout << temphead->val << " ";
        temphead = temphead->next;
    } cout << endl;
    cout << current->val << endl;
    slow = head;
    while(slow != current and current != NULL){
        cout << slow->val << " " << current->val << endl;
        if(slow->val != current->val) return false;
        slow = slow->next;
        current = current->next;
    }
    return true;
}
int main(){
    // Node* head =  new Node(10);
    // cout << head->val << endl;
    // makeSize10LinkedList();
    // insertion();
    Node* head = new Node(1);
    Node* temp = head;
    for(int i = 2; i <= 11; i++){
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = temp->next;
    }
    for(int i = 11; i >= 1; i--){
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = temp->next;
    }   
    // temp = head;
    // while(temp != NULL){
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // } cout << endl;
    // // Deletion();
    // deleteNodeRecursion(&head, 5);
    temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    } cout << endl;
    nthNode(&head, 5);
    findMid(head);

    if(checkPalindromeUsingReverse(head)) cout << "it is palindromic!"; else cout << "No it's not!"; cout << endl;
}
