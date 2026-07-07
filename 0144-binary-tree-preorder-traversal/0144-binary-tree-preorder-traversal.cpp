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
    void pre(TreeNode*root,vector<int>& r){
        if(root==NULL)return;
        r.push_back(root->val);
        pre(root->left,r);
        pre(root->right,r);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        pre(root,r);
        return r;
    }
};