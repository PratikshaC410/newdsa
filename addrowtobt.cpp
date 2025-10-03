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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
            if (depth == 1) {
           
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        addRow(root, val, 1, depth);
        return root;
    }

private:
    void addRow(TreeNode* node, int val, int currentDepth, int targetDepth) {
        if (!node) return;

        if (currentDepth == targetDepth - 1) {
          
            TreeNode* oldLeft = node->left;
            TreeNode* oldRight = node->right;

            node->left = new TreeNode(val);
            node->left->left = oldLeft;

            node->right = new TreeNode(val);
            node->right->right = oldRight;
        } else {
            addRow(node->left, val, currentDepth + 1, targetDepth);
            addRow(node->right, val, currentDepth + 1, targetDepth);
        } 
    }
};