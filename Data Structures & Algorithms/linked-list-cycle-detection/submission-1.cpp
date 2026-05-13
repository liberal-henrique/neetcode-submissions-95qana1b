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

#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> addresses;
        ListNode* current = head;

        while(current != nullptr) {
            if (addresses.find(current) == addresses.end())
                addresses.insert(current);
            else 
                return true;
            current = current->next;
        }
        return false;
    }
};
