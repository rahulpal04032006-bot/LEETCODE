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
bool isValid(TreeNode* root,long long min1,long long max1){
    if(root == NULL){
        return true;
    }
    if(root->val >= max1 || root->val <= min1){
        return false;
    }
   
 return    isValid(root->left,min1,root->val) &&  isValid(root->right,root->val,max1); 
   
}
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};