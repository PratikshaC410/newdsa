class Solution {
public:
    // Function to detect loop in the linked list.
    bool detectLoop(Node* head) {
        if (!head) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move by 1
            fast = fast->next->next;     // move by 2

            if (slow == fast) {
                return true;  // loop detected
            }
        }
        return false; // no loop
    }
};