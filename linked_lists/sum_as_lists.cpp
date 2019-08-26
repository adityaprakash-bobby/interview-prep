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

/*
    Function to add two lists in reverse and return the resultant list in same
    manner in reverse
*/
ListNode* addAsLists(ListNode* A, ListNode* B) {

    int val;
    int carry = 0;

    ListNode* head;
    ListNode* res = NULL;
    ListNode* temp_a = A;
    ListNode* temp_b = B;
    
    // Handle empty lists
    if (A == NULL) {
        return B;
    } else if (B == NULL) {
        return A;
    } else if (A == NULL && B == NULL) {
        return res;
    }
    
    // Add numbers till one of the list goes till the end
    while (temp_a != NULL && temp_b != NULL) {
        
        val = temp_a->val + temp_b->val + carry;
        carry = val / 10;
        
        ListNode* new_node = new ListNode(val%10);
        if (res == NULL) {
            res = new_node;
            head = new_node;
        } else {
            res->next = new_node;
            res = res->next;
        }
        
        temp_a = temp_a->next;
        temp_b = temp_b->next;
    
    }
    
    // Add remaining elements of A if B has reached its end
    while (temp_a != NULL) {
        
        val = temp_a->val + carry;
        carry = val / 10;
        
        ListNode* new_node = new ListNode(val%10);
        if (res == NULL) {
            res = new_node;
            head = new_node;
        } else {
            res->next = new_node;
            res = res->next;
        }
        temp_a= temp_a->next;
    }

    // Add remaining elements of B if A has reached its end
    while (temp_b != NULL) {
        
        val = temp_b->val + carry;
        carry = val / 10;
        
        ListNode* new_node = new ListNode(val%10);
        if (res == NULL) {
            res = new_node;
            head = new_node;
        } else {
            res->next = new_node;
            res = res->next;
        }
        temp_b = temp_b->next;
    }
    
    // Add the end carry, if present, to the result list
    if (carry == 1) {
        ListNode* new_node = new ListNode(1);
        res->next = new_node;
    }
    
    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    ListNode* result;
    ListNode* A = NULL;
    ListNode* B = NULL;

    // Number 1 = 3 4 2
    A = insertNode(A, 2);
    A = insertNode(A, 4);
    A = insertNode(A, 3);
    
    // Number 2 = 4 6 5
    B = insertNode(B, 5);
    B = insertNode(B, 6);   
    B = insertNode(B, 4);   

    result = addAsLists(A, B);

    printLL(result);

    return 0;
}