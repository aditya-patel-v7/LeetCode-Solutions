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
class Solution {
public:
    unordered_set<int> del;
    vector<TreeNode*> ans;

    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;

        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if (del.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int x : to_delete)
            del.insert(x);

        if (root && !del.count(root->val))
            ans.push_back(root);

        dfs(root);

        return ans;
    }
};