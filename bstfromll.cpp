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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      int size = getLength(head);
        curr = head;
        return buildBST(0, size - 1);
    }

private:
    ListNode* curr;

    // Count length of linked list
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    // Recursively build BST in inorder fashion
    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        // Build left subtree
        TreeNode* leftChild = buildBST(left, mid - 1);

        // Root = current list node
        TreeNode* root = new TreeNode(curr->val);
        root->left = leftChild;

        // Move to next list node
        curr = curr->next;

        // Build right subtree
        root->right = buildBST(mid + 1, right);

        return root;
    }
};