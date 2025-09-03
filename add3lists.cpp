/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Utility: reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Utility: remove leading zeros
    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0 && head->next) {
            head = head->next;
        }
        return head;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Step 1: Remove leading zeros from input lists
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        // Step 2: Reverse both lists
        head1 = reverseList(head1);
        head2 = reverseList(head2);

        Node dummy(0);
        Node* current = &dummy;
        int carry = 0;

        // Step 3: Perform addition
        while (head1 || head2 || carry) {
            int val1 = (head1) ? head1->data : 0;
            int val2 = (head2) ? head2->data : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new Node(sum % 10);
            current = current->next;

            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }

        // Step 4: Reverse the result
        Node* result = reverseList(dummy.next);

        // Step 5: Remove leading zeros from result
        result = removeLeadingZeros(result);

        return result;
    }
};
