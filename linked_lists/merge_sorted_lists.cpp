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
    Function to merge two sorted lists and return the resultant list
    maintianing the same order
*/
ListNode* mergeLists(ListNode* A, ListNode* B) {

    ListNode* temp_a = A;
    ListNode* temp_b = B;
    ListNode* head;
    ListNode* res = NULL;

    // Handle empty lists
    if (A == NULL && B != NULL) {
        return B;
    } else if (B == NULL && A != NULL) {
        return A;
    } else if (A == NULL && B == NULL) {
        return res;
    }
    
    while (temp_a != NULL && temp_b != NULL) {

        if (temp_a->val < temp_b->val) {

            ListNode* new_node = new ListNode(temp_a->val);

            if (res == NULL) {
                res = new_node;
                head = new_node;
            } else {
                res->next = new_node;
                res = res->next;
            }

            temp_a = temp_a->next;
        
        } else {

            ListNode* new_node = new ListNode(temp_b->val);

            if (res == NULL) {
                res = new_node;
                head = new_node;
            } else {
                res->next = new_node;
                res = res->next;
            }

            temp_b = temp_b->next;
        
        }

    }

    while (temp_b != NULL) {

        ListNode* new_node = new ListNode(temp_b->val);

        res->next = new_node;
        res = res->next;
        temp_b = temp_b->next;
    }

    while (temp_a != NULL) {

        ListNode* new_node = new ListNode(temp_a->val);

        res->next = new_node;
        res = res->next;
        temp_a = temp_a->next;
    }

    return head;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
    ListNode* result;
    ListNode* A = NULL;
    ListNode* B = NULL;

    A = insertNode(A, 2);
    A = insertNode(A, 3);
    A = insertNode(A, 4);
    
    B = insertNode(B, 1);
    B = insertNode(B, 2);   
    B = insertNode(B, 6);   

    result = mergeLists(A, B);

    printLL(result);

    return 0;
}