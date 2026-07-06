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
    void dfs(TreeNode* root, int val, int depth, int currDepth) {
        if (root == nullptr)
            return;

        if (currDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            newLeft->left = root->left;
            newRight->right = root->right;

            root->left = newLeft;
            root->right = newRight;

            return;
        }

        dfs(root->left, val, depth, currDepth + 1);
        dfs(root->right, val, depth, currDepth + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        dfs(root, val, depth, 1);
        return root;
    }
};