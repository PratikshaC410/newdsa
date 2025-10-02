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
    int rangeSumBST(TreeNode* root, int low, int high) {
            if (!root) return 0;

        int sum = 0;

        // If root value is in range, include it
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // Only traverse left subtree if it could contain values >= low
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        // Only traverse right subtree if it could contain values <= high
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};