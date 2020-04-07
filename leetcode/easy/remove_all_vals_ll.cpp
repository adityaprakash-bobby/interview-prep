using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp;
        ListNode* prev;
        
        temp = head;
        
        while (temp != NULL && temp->val == val) {            
            head = temp->next;
            // free(temp);
            temp = head;
        } 
        
        while (temp != NULL) {
            cout << "temp->val" << temp->val << endl;
            while (temp != NULL && temp->val != val) { 
                prev = temp; 
                temp = temp->next;
            }
        
            if (temp == NULL) {
                return head;
            }
            
            prev->next = temp->next;
            // free(temp);
            temp = prev->next;
        }
        return head;
    }
};