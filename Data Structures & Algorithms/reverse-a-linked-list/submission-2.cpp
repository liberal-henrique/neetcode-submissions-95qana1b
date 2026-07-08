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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode* nextStep = head->next;
        ListNode* previous = nullptr;
        while(nextStep) {
            head->next = previous;
            previous = head;
            head = nextStep;
            nextStep = nextStep->next;
        }
        head->next = previous;
        return head;
    }
};
