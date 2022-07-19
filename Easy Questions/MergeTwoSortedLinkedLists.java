//Fast working solution

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode prehead = new ListNode(-1);
        
        ListNode prev = prehead;
        while (list1 != null && list2 != null) {
            if(list1.val <= list2.val) {
                prev.next = list1;
                list1 = list1.next;
            }
            else {
                prev.next = list2;
                list2 = list2.next;
            }
            prev = prev.next;
        }
        
        prev.next = list1 == null ? list2 : list1;
            
        return prehead.next;
    }
}

//My intital failed first solution

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode headAns;
        ListNode currNode1, currNode2;
        if(list1.val > list2.val) {
            headAns = list2;
            currNode2 = list2.next;
            currNode1 = list1;
            
        }
        else {
            headAns = list1;
            currNode1 = list1.next;
            currNode2 = list2;
        }
                
        while (currNode1.next != null || currNode2.next != null) {
            if(currNode1.next != null && currNode2.next != null) {
                if(currNode1.val > currNode2.val) {
                    ListNode temp = new ListNode(currNode2.val, currNode2.next);
                    currNode2.next = currNode1;
                    currNode2 = temp;
                    
                }
                else {
                    ListNode temp = new ListNode(currNode1.val, currNode1.next);
                    currNode1.next = currNode2;
                    currNode1 = temp;
                }
            }
            else {
                if(currNode1.next == null) {
                    currNode1.next = currNode2;
                    break;
                }
                else {
                    currNode2.next = currNode1;
                    break;
                }
            }
        }
        
        return headAns;
    }
}