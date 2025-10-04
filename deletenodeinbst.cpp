class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 
            else {
                // Node with two children → get inorder successor (smallest in right subtree)
                TreeNode* minNode = findMin(root->right);
                root->val = minNode->val; // copy value
                root->right = deleteNode(root->right, minNode->val); // delete successor
            }
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
};
