/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value from the next node
        node->val = node->next->val;
        
        // Skip the next node
        node->next = node->next->next;
    }
};
