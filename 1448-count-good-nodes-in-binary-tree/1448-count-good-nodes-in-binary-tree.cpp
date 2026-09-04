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
int count = 0;
  void good(TreeNode* root ,int maxNode){
    if(root == NULL){
        return ;
    }
   
    if(root->val >= maxNode){
        count++;
    }
    maxNode = max(root->val,maxNode);
     good(root->left,maxNode);
     good(root->right,maxNode);

}
    int goodNodes(TreeNode* root) {
       good(root,root->val);
       return count;  
    }
};