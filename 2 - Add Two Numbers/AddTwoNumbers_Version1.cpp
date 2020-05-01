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
        int carryOver = 0, sum = 0;
        sum = l1->val + l2->val;
        carryOver = sum / 10;
        ListNode* currentNode = new ListNode( sum % 10);
        ListNode* returnNode = currentNode;

        while (1) {
            if ( carryOver == 0 && l1->next == NULL && l2->next == NULL ){
                return returnNode;
            }
            
            
            sum = 0;
            if ( carryOver ){
                sum = carryOver;
            }
            
            if ( l1->next ){
                l1 = l1->next;
                sum += l1->val;
            }
            
            if ( l2->next ){
                l2 = l2->next;
                sum += l2->val;
            }
            
            carryOver = sum / 10;
            ListNode* nextNode = new ListNode(sum % 10); 
            
            currentNode->next = nextNode;
            currentNode = nextNode;
        }
    }
};