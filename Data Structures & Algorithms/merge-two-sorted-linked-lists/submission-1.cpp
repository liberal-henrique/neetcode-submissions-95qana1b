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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;
        
        while(list1 || list2) {
            if(list1 && list2 && list1->val <= list2->val) {
                tail->next = new ListNode(list1->val);
                tail = tail->next;
                list1 = list1->next;
            } else {
                if (list2) {
                    tail->next = new ListNode(list2->val);
                    tail = tail->next;
                    list2 = list2->next;
                }
            }
            if(!list1 && list2) {
                tail->next = new ListNode(list2->val);
                tail = tail->next;
                list2 = list2->next;
            }
            if(list1 && !list2) {
                tail->next = new ListNode(list1->val);
                tail = tail->next;
                list1 = list1->next;
            }
        }
        return dummy.next;
    }

};
