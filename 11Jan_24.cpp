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
class Solution
{
public:
    pair<int, int> func(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return {1e9, -1e8};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {root->val, root->val};
        }
        pair<int, int> left = func(root->left, maxi);
        pair<int, int> right = func(root->right, maxi);
        int mini = min(left.first, right.first);
        int lmaxi = max(left.second, right.second);
        maxi = max(maxi, abs(root->val - mini));
        maxi = max(maxi, abs(root->val - lmaxi));
        return {min(mini, root->val), max(lmaxi, root->val)};
    }
    int maxAncestorDiff(TreeNode *root)
    {
        int maxi = 0;
        func(root, maxi);
        return maxi;
    }
};