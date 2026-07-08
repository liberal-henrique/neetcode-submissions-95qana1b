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
    // 1-2-3-4-5
    // 5-4-3-2-1

    ListNode* reverseLinkedList(ListNode* head, ListNode* previous) {
        if (!head->next) {
            head->next = previous;
            return head;
        }
        ListNode* result = reverseLinkedList(head->next, head);
        head->next = previous;
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        head = reverseLinkedList(head, nullptr);
        return head;
    }
};
