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
    
     int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        if(root->left==NULL and root->right==NULL){
            return 1;
        }
        
        
        if(root->left == NULL) return helper(root->right) +1;

        if(root->right==NULL) return helper(root->left) +1;

        
        return min(helper(root->left),helper(root->right))+1;

     }
    int minDepth(TreeNode* root) {
       
        return  helper(root);
    }
};