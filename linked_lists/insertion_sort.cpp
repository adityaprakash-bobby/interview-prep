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

ListNode* insertionSort(ListNode* head) {

    ListNode* insert_ptr = head;
    ListNode* curr_ptr = head->next;

    while (curr_ptr != NULL) {

        while (insert_ptr != curr_ptr) {

            // Compare the elements from head to the previous of current
            // pointer. If greater swap, else just increment the intertion
            // pointer

            if (insert_ptr->val > curr_ptr->val) {
                int temp = curr_ptr->val;
                curr_ptr->val = insert_ptr->val;
                insert_ptr->val = temp;
            }

            insert_ptr = insert_ptr->next;
            
        }

        // Place the insertion pointer back to the head of the list and 
        // increment the current pointer
        insert_ptr = head;
        curr_ptr = curr_ptr->next;

    }

    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    ListNode* result;
    ListNode* head = NULL;

    head = insertNode(head, 2); 
    head = insertNode(head, 1); 
    head = insertNode(head, 3); 
    head = insertNode(head, 4);

    result = insertionSort(head);

    printLL(head);

    return 0;
}