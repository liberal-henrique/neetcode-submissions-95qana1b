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
        if (!l1 && !l2)
            return l1;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        ListNode *newNode;

        int valueFromPtr1 = 0;
        
        int valueFromPtr2 = 0;
        int result = 0;
        int previousRest = 0;

        while (l1 || l2) {
            valueFromPtr1 = (!l1) ? 0 : l1->val;
            valueFromPtr2 = (!l2) ? 0 : l2->val;
            
            result = valueFromPtr1 + valueFromPtr2 + previousRest;
            previousRest = 0;

            newNode = new ListNode();

            tail->next = newNode;
            tail = newNode;

            if (result > 9) 
                previousRest = result / 10;
            result = result % 10;
            newNode->val = result;

            if (l1) 
                l1 = l1->next;
            if (l2) 
                l2 = l2->next;
        }
        if (previousRest > 0) {
            newNode = new ListNode();
            tail->next = newNode;
            tail = newNode;
            newNode->val = previousRest;
        }
        return dummy->next;        
    }
};
