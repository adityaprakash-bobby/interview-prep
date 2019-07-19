#include <iostream>

using namespace std;

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

/* Function to reverse the linked list */
Node* reverseLL(Node* head) {

    Node* prev_node = NULL;
    Node* curr_node = head;
    Node* next_node;

    while (curr_node != NULL) {

        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;

    }

    head = prev_node;

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

    head = reverseLL(head);

    printLL(head);

    return 0;
}