class Solution {
  public:
    // Helper function to check BST property
    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (!root) return true; // Empty tree is a BST

        // The current node must be within the allowed range
        if (root->data <= minVal || root->data >= maxVal)
            return false;

        // Check recursively for left and right subtrees
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }

    // Main function
    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};
