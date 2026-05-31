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

// If I move the last one, I update what it is the last

class Solution {
public:
    ListNode* getLast(ListNode* head) {
        ListNode* last = head;
        ListNode* beforeLast = head;
        while (last->next) {
            if (!last->next->next) 
                beforeLast = last;
            last = last->next;
        }
        beforeLast->next = NULL;
        return last;
    }

    int sizeList(ListNode* head) {
        int size = 0;
        ListNode* last = head;
        while (last->next) {
            size++;
            last = last->next;
        }
        return size;
    }

    ListNode * swapNodes(ListNode* head, ListNode* root, int sizeList) {    
        if (sizeList == 0 || !head || !root)
            return head;
        ListNode* last = getLast(root);
        ListNode* swap = root->next;
        root->next = last;
        last->next = swap;
        return swapNodes(head, last->next, sizeList - 1);
    }

    void reorderList(ListNode* head) {
        if (!head)
            return;
        int size = sizeList(head) / 2;
        int sizeList = (size % 2 == 0) ? size : size + 1; 
        swapNodes(head, head, sizeList);
    }
};
