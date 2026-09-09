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
int sumof = 0;
void sum(TreeNode* root,int currlevel,int x){
    if(root == NULL){
        return;
    }
    if(currlevel == x){
        sumof += root->val;
        return ;
    }
    sum(root->left,currlevel+1,x);
    sum(root->right,currlevel+1,x);

}
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) + 1;
}
    int deepestLeavesSum(TreeNode* root) {
        int x = height(root);
        sum(root,1,x);
        return sumof;
    }
};