#include <iostream>

using namespace std;

/* Class to hold the node data */
class Node {
   
    public:
        
        int data;
        Node* next;

};

/* Function to insert node at the end of a list */
Node* insertNode(Node* head, int data) {

    Node* temp = head;
    Node* new_node = new Node();
    
    new_node->data = data;
    new_node->next = NULL;

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

/* Function to remove duplicates from the linked list */
Node* removeDuplicates(Node* head) {

    int prev_data = head->data;
    Node* curr = head;

    while (curr != NULL) {

    }

    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    Node* head = NULL;

    head = insertNode(head, 100);
    head = insertNode(head, 100);
    head = insertNode(head, 200);
    head = insertNode(head, 200);
    head = insertNode(head, 300);   
    head = insertNode(head, 300);   
    head = insertNode(head, 400);   

    printLL(head);

    head = removeDuplicates(head);

    printLL(head);

    return 0;
}