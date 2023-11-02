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
    pair<int, int> func(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        pair<int, int> left = func(root->left, ans);
        pair<int, int> right = func(root->right, ans);
        int height = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;
        if (sum / height == root->val)
        {
            ans++;
        }
        return {height, sum};
    }
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        pair<int, int> x = func(root, ans);
        return ans;
    }
};