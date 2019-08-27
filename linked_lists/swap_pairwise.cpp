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

/* Function to swap nodes pair-wise */
ListNode* swapPairwise(ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* first = head;
    ListNode* second = head->next;
    
    int temp;

    while (first && second) {

        temp = first->val;
        first->val = second->val;
        second->val = temp;

        first = second->next;

        if (second->next) {
            second = second->next->next;
        } else {
            break;
        }
    
    }

    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    ListNode* result;
    ListNode* head = NULL;

    head = insertNode(head, 1); 
    head = insertNode(head, 2); 
    head = insertNode(head, 3); 
    head = insertNode(head, 4);

    result = swapPairwise(head);

    printLL(result);

    return 0;
}