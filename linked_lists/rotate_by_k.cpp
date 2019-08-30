#include <iostream>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}

};

/* Function to insert node at the end of a list */
ListNode* insertNode(ListNode* head, int data) {

    ListNode* temp = head;
    ListNode* new_node = new ListNode(data);
    
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
void printLL(ListNode* head) {

    ListNode* temp = head;

    if (head == NULL) {
        
        cout << "\n";
        return;
    
    }

    while (temp != NULL) {

        cout << temp->val << " ";
        temp = temp->next;

    }

    cout << "\n";

    return;
}

/* Function to rotate list by k-steps */
ListNode* rotateByK(ListNode* head, int k) {

    // Determine the length of the linked list
    ListNode* temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int final_shift = k%length;
    int break_length = length - final_shift;

    ListNode* ptr = head;
    
    // Handle case if k = 0 after MOD
    if (final_shift == 0) {
        return head;
    }

    // Move the pointer to end node of list part1
    while (--break_length) {
        ptr = ptr->next;
    }

    // Save the address of next halve and set the end of first part as NULL
    ListNode* part2 = ptr->next;
    temp = ptr->next;
    ptr->next = NULL;

    // Traverse to the end of second halve and attach the first part to its end
    // and update head value
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
    head = part2;

    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    ListNode* head = NULL;

    head = insertNode(head, 1); 
    head = insertNode(head, 2); 
    head = insertNode(head, 3); 
    head = insertNode(head, 4);
    head = insertNode(head, 3); 
    head = insertNode(head, 2); 
    head = insertNode(head, 1); 

    
    printLL(rotateByK(head, 90));
 
    return 0;
}