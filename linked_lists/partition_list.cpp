#include <iostream>

using namespace std;

/* Class to hold the node data */
class Node {
   
    public:
        
    int data;
    Node* next;

    Node(int x) : data(x), next(NULL) {}

};

/* Function to insert node at the end of a list */
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

// Function to partition list around data 'x' in the list maintaining the 
// order in the lists
Node* partitionList(Node* head, int x) {

    Node* less = NULL;
    Node* more = NULL;
    Node* ptr1 = less;
    Node* ptr2 = more;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data < x) {
        
            if (ptr1 == NULL) {
                ptr1 = new Node(temp->data);
                less = ptr1;
            } else {
                less->next = new Node(temp->data);
                less = less->next;
            }
        
        } else {

            if (ptr2 == NULL) {
                ptr2 = new Node(temp->data);
                more = ptr2;
            } else {
                more->next = new Node(temp->data);
                more = more->next;
            }

        }

        Node* temp2 = temp;
        temp = temp->next;
        free(temp2);
        head = temp;
    
    }

    if (ptr1 == NULL) {
        return ptr2;
    }

    less->next = ptr2;
    return less;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* part = NULL;

    head = insertNode(head, 100);
    // head = insertNode(head, 200);   
    // head = insertNode(head, 300);   
    // head = insertNode(head, 400);   

    printLL(head);

    part = partitionList(head, 100);

    printLL(part);

    return 0;
}