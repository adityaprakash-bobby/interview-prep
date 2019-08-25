#include <iostream>

using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int x) : data(x), next(NULL) {}

};

/* Function to insert a node into the linkedlist */
Node* insertNode(Node* head, int data) {

    Node* temp = head;
    Node* new_node = new Node(data);
    
    if (head == NULL) {
        
        head = new_node;
        return head;

    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;

}

/* Function to print the list given the head */
void printLL(Node* head) {

    Node* temp = head;

    if (head == NULL) {
        
        cout << "\n";
        return;
    
    }

    while (temp != NULL) {

        cout << temp->data << " ";
        temp = temp->next;

    }

    cout << "\n";

    return;
}

/* Function to remove the nth node from the end of a linedlist */
Node* removeNthNode(Node* head, int n) {

    int length = 0;
    Node* curr = head;
    Node* prev = head;
    
    // If list is empty return the empty list itself
    if (head == NULL) {
        return head;
    }

    // If list is not empty, calculate the length of the list
    while (curr != NULL) {
        curr = curr->next;
        length++;
    }

    // If n > length, delete the first node of the list and return the head
    if (n >= length) {

        curr = head;
        
        if (length == 1) {
            head = NULL;
        } else {
            head = curr->next;
        }

        free(curr);
        return head;
    }
    
    curr = head;

    // If not the above cases, mark the node to be deleted(curr) and its
    // previous node(prev)
    for (int i = 0; i < length - n; i++) {
        prev = curr;
        curr = curr->next;
    }

    // Set the next node of previous node as the next node of the node to be
    // deleted and delete the current node
    prev->next = curr->next;
    free(curr);
    
    // return the head of the modified list
    return head;
}


/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    Node* head = NULL;

    head = insertNode(head, 100);
    head = insertNode(head, 200);   
    head = insertNode(head, 300);   
    head = insertNode(head, 400);   

    printLL(head);

    int n = 1;

    head = removeNthNode(head, n);

    printLL(head);

    return 0;
}