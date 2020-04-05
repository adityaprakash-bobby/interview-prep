struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp;
        temp = res;
        
        ListNode* itr1;
        ListNode* itr2; 
        ListNode* prev; 
            
        itr1 = l1;
        itr2 = l2;
        
        int digit_sum = 0, carry = 0;
        
        while (itr1 != NULL && itr2 != NULL) {
            
            digit_sum = carry + itr1->val + itr2->val;
            carry = digit_sum / 10;
            temp->val = digit_sum % 10;
            
            prev = temp;
            temp->next = new ListNode(0);
            
            temp = temp->next;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        
        while (itr1 != NULL) {
            digit_sum = carry + itr1->val;
            carry = digit_sum / 10;
            temp->val = digit_sum % 10;

            prev = temp;
            temp->next = new ListNode(0);
            
            temp = temp->next;
            itr1 = itr1->next;
        }
        
        while (itr2 != NULL) {
            digit_sum = carry + itr2->val;
            carry = digit_sum / 10;
            temp->val = digit_sum % 10;
            
            prev = temp;
            temp->next = new ListNode(0);   

            temp = temp->next;
            itr2 = itr2->next;
        }
        
        if (carry != 0) {
            temp->val = carry;
        } else {
            prev->next = NULL;
        }
        
        return res;
    }
};