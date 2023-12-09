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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *pre;
        if (root == NULL)
        {
            return v;
        }
        TreeNode *curr = root;
        while (curr)
        {
            int count = 0;
            pre = NULL;
            if (curr->left == NULL)
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while (pre->right && pre->right != curr)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return v;
    }
};