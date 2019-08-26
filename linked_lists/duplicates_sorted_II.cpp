#include <iostream>
#include <climits>

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

/* Function to remove duplicates from the linked list */
Node* removeDuplicates(Node* head) {

    // If the list has no elements or a single element, return the head as such
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Make a dummy node that seems to be in the beginning of the given list
    Node* dummy = new Node(INT_MIN);
    dummy->next = head;

    // Will be using 3 pointers for the job to be done. 'prev' marks the dummy
    // start point, 'curr' to the head and 'next' tracks where the same data 
    // nodes differ
    Node* prev = dummy;
    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {

        Node* next = curr->next;

        if (curr->data == next->data) {
            
            // Places the curr and the next pointer in the boundary of two
            // different numbers.             
            while (curr->next != NULL && curr->data == next->data) {
                curr = curr->next;
                next = next->next;
            }

            // set the links for the main list
            prev->next = next;
            curr = next;

        } else {

            prev = prev->next;
            curr = curr->next;

        }

    }

    return dummy->next;
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

    // printLL(head);

    head = removeDuplicates(head);

    printLL(head);

    return 0;
}