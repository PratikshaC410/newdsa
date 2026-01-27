class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2, result;

        inorder(root1, v1);
        inorder(root2, v2);

        // merge two sorted vectors
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
                result.push_back(v1[i++]);
            else
                result.push_back(v2[j++]);
        }

        while (i < v1.size())
            result.push_back(v1[i++]);
        while (j < v2.size())
            result.push_back(v2[j++]);

        return result;
    }

private:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};
