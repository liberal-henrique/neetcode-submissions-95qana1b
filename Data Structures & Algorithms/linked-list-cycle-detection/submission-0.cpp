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
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode* head) {
        vector<ListNode*> addresses;
        ListNode* current = head;

        while(current != nullptr) {
            if (find(addresses.begin(), addresses.end(), current->next) == addresses.end() || current->next == nullptr)
                addresses.push_back(current->next);
            else 
                return true;
            current = current->next;
        }
        return false;
    }
};
