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
#include <vector>
#include <iostream>
using namespace std;
using namespace std;

class Solution {
public:
    vector<int> getValuesFromList(ListNode* head) {
        vector<int> result;
        ListNode* curr = head;
        while (curr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }

    void deletePositionInLinkedList(ListNode* head, int position) {
        while (position > 1) {
            position--;
            head = head->next;
        }
        head->next = head->next->next;
    }

    size_t linkedListSize(ListNode* head) {
        ListNode* curr = head;
        size_t counter = 0;
        while (curr) {
            counter++;
            curr = curr->next;
        }
        return counter;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) 
            return head;
        
        if (linkedListSize(head) == 1) {
            head = nullptr;
            return head;
        }
        
        vector<int> arrayWithListValues = getValuesFromList(head);
        int valueToDelete = arrayWithListValues.size() - n;
        if (valueToDelete == 0) {
            head = head->next;
        } else {
            deletePositionInLinkedList(head, valueToDelete);
        }
        return head;
    }
};
