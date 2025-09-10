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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Connect the last node to the head to make it circular
        temp->next = head;

        // Step 3: Find the new head after rotation
        k = k % length;  // In case k is greater than length
        int stepsToNewHead = length - k;

        while (stepsToNewHead--) {
            temp = temp->next;
        }

        // Step 4: Break the circle
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
