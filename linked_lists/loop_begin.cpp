#include <iostream>
#include <unordered_set>

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

/* Function to find a cycle in list, if any and return the beginning node */
ListNode* returnVal(ListNode* A) {

    unordered_set<ListNode*> set;
    ListNode* head = A;

    while (head != NULL) { 
        
        if (set.find(head) != set.end()) {
            return head; 
        }    
        set.insert(head); 
  
        head = head->next; 
    
    } 
  
    return NULL;
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

    head->next->next->next->next = head->next->next; 

    result = returnVal(head);

    cout << result->val << endl;

    return 0;
}