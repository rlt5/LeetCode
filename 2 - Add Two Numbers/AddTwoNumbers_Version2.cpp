/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0, sum = 0, l1Val = 0, l2Val = 0;
        ListNode* returnNode = new ListNode(0);
        ListNode* currentNode = returnNode;

        while ( l1 && l2) {
            l1Val = ( l1 ) ? l1->val : 0;
            l2Val = ( l2 ) ? l2->val : 0;
            
            sum = carryOver + l1Val + l2Val;
            carryOver = sum / 10;

            currentNode->next = new ListNode(sum % 10); 
            currentNode = currentNode->next;
            
            if ( l1 ) l1 = l1->next;
            if ( l2 ) l2 = l2->next;
        }
        
        while ( l1 ) {
            sum = carryOver + l1->val;
            carryOver = sum / 10;

            currentNode->next = new ListNode(sum % 10); 
            currentNode = currentNode->next;
            l1 = l1->next;
        }

        while ( l2 ) {
            sum = carryOver + l2->val;
            carryOver = sum / 10;

            currentNode->next = new ListNode(sum % 10); 
            currentNode = currentNode->next;
            l2 = l2->next;
        }
        
        if ( carryOver )
            currentNode->next = new ListNode(carryOver);
        return returnNode->next;
    }
};