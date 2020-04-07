using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // if no head
        if (head == NULL) {
            return head;
        }
        
        // else, create a dummy head node
        ListNode* dummy = new ListNode(-999);
        dummy->next = head;
        
        ListNode* prev;
        ListNode* curr;
        
        // make prev point to the dummy and curr to the actual head
        prev = dummy;
        curr = dummy->next;
        
        while (curr != NULL) {
            // node does not have the value, so set prev's next to 
            // the curr and prev to the curr
            if (curr->val != val) {
                prev->next = curr;
                prev = curr;
            } else {
                prev->next = curr->next;
            }
            
            curr = curr->next;
        }
        return dummy->next;
    }
};