class Solution {
private:
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;
        reverseInorder(node->right, counter, k, kLargest);

        counter++;
        if (counter == k) {
            kLargest = node->val;
            return;
        }
        reverseInorder(node->left, counter, k, kLargest);
    }

    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        inorder(node->left, counter, k, kSmallest);
        counter++;
        if (counter == k) {
            kSmallest = node->val;
            return;
        }
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(TreeNode* root, int k) {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
    
        int counter = 0; 
        inorder(root, counter, k, kSmallest);
        counter = 0; 
        reverseInorder(root, counter, k, kLargest);

        return make_pair(kSmallest, kLargest);
    }
};
