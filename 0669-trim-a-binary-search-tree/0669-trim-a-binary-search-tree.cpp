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
TreeNode* todel(TreeNode* root,int low,int high){
    if(root == NULL){
        return NULL;
    }
    TreeNode* curr = root;
    if(root->val < low){
        return todel(root->right,low,high);
    }
    if(root->val > high){
        return todel(root->left,low,high);
    }else if(root->val >= low && root->val <= high){
        curr->left = todel(curr->left,low,high);
        curr->right = todel(curr->right,low,high);
    }
    return curr;
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return todel(root,low,high);
    }
};