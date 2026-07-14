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
    int ans,maxd=-1;

    void depth(TreeNode*x,int d){
       if(!x)return;
       if(!x->left && !x->right){
       if(d>maxd){
        maxd=d;
        ans=x->val;
       }
       }
       depth(x->left,d+1);
       depth(x->right,d+1);

        }
    
    int findBottomLeftValue(TreeNode* root) {
     depth(root,0);
      
    return ans; }
};