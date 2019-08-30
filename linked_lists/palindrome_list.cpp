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

bool isPalindromeList(ListNode* head) {

    // If list is empty or is having single element, then return true
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // First find the center of the list using slow and fast pointers
    ListNode* slow_ptr = head;
    ListNode* fast_ptr = head;

    while (fast_ptr->next != NULL && fast_ptr->next->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Mark the next node of center as the second head and reverse the list
    // from this point till the end.
    ListNode* second_head = slow_ptr->next;
    ListNode* prev_node = NULL;
    ListNode* curr_node = second_head;
    ListNode* next_node;

    while (curr_node != NULL) {

        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;

    }

    slow_ptr->next = prev_node;

    // Now compare the list the from the beginning and the part of the list
    // starting at location of second head
    second_head = slow_ptr->next;
    
    while (second_head != NULL) {

        if (second_head->val != head->val) {
            return false;
        }
        second_head = second_head->next;
        head = head->next;
    } 

    return true;
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

    
    cout << isPalindromeList(head) << endl;
 
    return 0;
}