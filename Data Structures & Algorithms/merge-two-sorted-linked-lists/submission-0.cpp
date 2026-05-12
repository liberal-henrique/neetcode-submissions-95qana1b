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
        ListNode head;    
        ListNode* current = &head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list2 == nullptr || list1->val <= list2->val) {
                current->next = new ListNode(list1->val);
                list1 = list1->next;
            } else if (list1 == nullptr || list2->val < list1->val) {
                current->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            current = current->next;
        }

        while (list1 != nullptr) {
            current->next = new ListNode(list1->val);
            current = current->next;
            list1 = list1->next;
        }
        
        while (list2 != nullptr) {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }
        return head.next;
    }

};
