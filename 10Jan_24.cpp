/**
 * Definition for a binary tree TreeNode.
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
    TreeNode *create_mapping(TreeNode *root, int target, map<TreeNode *, TreeNode *> &m)
    {
        TreeNode *result = NULL;
        queue<TreeNode *> q;
        q.push(root);
        m[root] = NULL;
        while (q.size())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == target)
            {
                result = front;
            }
            if (front->left)
            {
                m[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                m[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }

    int burntree(TreeNode *root, map<TreeNode *, TreeNode *> &m)
    {
        int ans = 0;
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        visited[root] = true;
        q.push(root);
        while (q.size())
        {
            int a = q.size();
            bool check = 0;
            while (a--)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && visited[front->left] == 0)
                {
                    check = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right && visited[front->right] == 0)
                {
                    check = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if (m[front] && visited[m[front]] == 0)
                {
                    check = 1;
                    q.push(m[front]);
                    visited[m[front]] = 1;
                }
            }
            if (check == 1)
            {
                ans++;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode *root, int target)
    {
        map<TreeNode *, TreeNode *> m;
        TreeNode *targetTreeNode = create_mapping(root, target, m);
        int ans = burntree(targetTreeNode, m);
        return ans;
    }
};