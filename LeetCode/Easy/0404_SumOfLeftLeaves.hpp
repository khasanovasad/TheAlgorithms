namespace LeetCode::Easy
{
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) { }
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) { }
    };

    int Sum(TreeNode* node, bool isLeft)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr && isLeft)
        {
            return node->val;
        }
        return Sum(node->left, true) + Sum(node->right, false);
    }

    int SumOfLeftLeaves(TreeNode* root)
    {
        return Sum(root, false);
    }
} // namespace LeetCode::Easy