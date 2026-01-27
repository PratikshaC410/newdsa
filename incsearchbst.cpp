class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *newRoot = nullptr;
        TreeNode *prev = nullptr;

        inorder(root, newRoot, prev);
        return newRoot;
    }

private:
    void inorder(TreeNode *node, TreeNode *&newRoot, TreeNode *&prev)
    {
        if (!node)
            return;

        inorder(node->left, newRoot, prev);

        // Process current node
        if (!newRoot)
        {
            newRoot = node; // first (smallest) node
        }
        if (prev)
        {
            prev->right = node; // link previous to current
        }

        node->left = nullptr; // remove left child
        prev = node;

        inorder(node->right, newRoot, prev);
    }
};
