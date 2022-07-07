//My super slow first version
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
        ListNode* ans = new ListNode();
        ListNode* result = ans;
        int cary = 0;
        int temp;
        int input;
        int count = 1;
        
        
        while (l1 != NULL || l2 != NULL) {
            
            if (l1 != NULL && l2 != NULL) {
                if (l1->val + l2->val + cary <= 9) {
                    input = l1->val + l2->val + cary;
                    cary = 0;
                }
                else {
                    temp = l1->val + l2->val + cary;
                    input = temp % 10;
                    cary = 1;
                }
                l1 = l1->next;
                l2 = l2->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }   
            
            if (l1 != NULL && l2 == NULL) {
                if (l1->val + cary <= 9) {
                    input = l1->val + cary;
                    cary = 0;
                }
                else {
                    input = 0;
                    cary = 1;
                }
                l1 = l1->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }
            
            if (l1 == NULL && l2 != NULL) {
                if (l2->val + cary <= 9) {
                    input = l2->val + cary;
                    cary = 0;
                }
                else {
                    input = 0;
                    cary = 1;
                }
                l2 = l2->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }
        } 
        if (cary == 1) {
                ans->next = new ListNode(1);
            }
        return result->next;
    }
}; 

//Nearly 4x faster version
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* result = ans;
        int cary = 0;
        int temp;
        int input;
        int count = 1;
         
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                temp = l1->val + l2->val + cary;
                input = temp % 10;
                cary = temp / 10;
                l1 = l1->next;
                l2 = l2->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }   
            
            else if (l1 != NULL && l2 == NULL) {
                temp = l1->val + cary;
                input = temp % 10;
                cary = temp / 10;
                l1 = l1->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }
            
            else if (l1 == NULL && l2 != NULL) {
                
                temp = l2->val + cary;
                input = temp % 10;
                cary = temp / 10;
                l2 = l2->next;
                ans->next = new ListNode(input);
                ans = ans->next;
            }
        } 
        
        if (cary == 1) {
                ans->next = new ListNode(1);
        }
        return result->next;
    }
}; 

//same speed but less variables
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* result = ans;
        int temp = 0;
         
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                temp = l1->val + l2->val + temp;
                ans->next = new ListNode(temp%10);
                temp = temp / 10;
                l1 = l1->next;
                l2 = l2->next;
                ans = ans->next;
            }   
            
            else if (l1 != NULL && l2 == NULL) {
                temp = l1->val + temp;
                ans->next = new ListNode(temp%10);
                temp = temp / 10;
                l1 = l1->next;
                ans = ans->next;
            }
            
            else if (l1 == NULL && l2 != NULL) { 
                temp = l2->val + temp;
                ans->next = new ListNode(temp%10);
                temp = temp / 10;
                l2 = l2->next;
                ans = ans->next;
            }
        } 
        
        if (temp == 1) {
                ans->next = new ListNode(1);
        }
        
        return result->next;
    }
}; 