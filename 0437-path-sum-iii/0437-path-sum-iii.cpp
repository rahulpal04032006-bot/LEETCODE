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
void path(TreeNode* root,long long target){
    if(root == NULL){
        return ;
    }
    target -= root->val;
    if(target == 0){
        count++;
    }
    path(root->left,target);
    path(root->right,target);
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        path(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
       
    }
};