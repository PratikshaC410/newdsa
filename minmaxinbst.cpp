TreeNode* findMin(TreeNode* root) {
    if (root == NULL || root->left == NULL) return root;
    return findMin(root->left);
}

TreeNode* findMax(TreeNode* root) {
    if (root == NULL || root->right == NULL) return root;
    return findMax(root->right);
}
