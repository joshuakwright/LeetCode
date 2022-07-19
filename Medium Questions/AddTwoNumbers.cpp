//My first working solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *num = new ListNode(-1);
        ListNode *place = num;
        int remainder = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int val1;
            int val2;
            if(l1 != NULL) {
                val1 = l1->val;
                l1 = l1->next;
            }
            else val1 = 0;
            if(l2 != NULL) {
                val2 = l2->val;
                l2 = l2->next;
            }
            else val2 = 0;
            
            int sum = val1 + val2 + remainder;
            remainder = sum / 10;
            sum %= 10;
            
            place->next = new ListNode(sum);
            place = place->next;
        }
        
        if(remainder) {
            place->next = new ListNode(1);
        }
        
        return num->next;
    }
};