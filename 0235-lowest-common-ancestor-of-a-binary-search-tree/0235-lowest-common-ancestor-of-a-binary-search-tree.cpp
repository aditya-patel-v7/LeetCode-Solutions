/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p || root==q || !root) return root;

        auto r1=lowestCommonAncestor(root->left,p,q);
        auto r2=lowestCommonAncestor(root->right,p,q);

        if (r1 && r2) return root;

        if (r1) return r1;
        if (r2) return r2;

        return nullptr;
    }
};