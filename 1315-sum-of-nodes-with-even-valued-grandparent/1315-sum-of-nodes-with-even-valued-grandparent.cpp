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
void sum(TreeNode* root,TreeNode* pr,TreeNode* gp,int& sum1){
    if(root == NULL){
        return;
    }
    if(gp != NULL && gp->val % 2 == 0){
        sum1 += root->val;
    }
    sum(root->left,root,pr,sum1);
    sum(root->right,root,pr,sum1);
}
    int sumEvenGrandparent(TreeNode* root) {
        int sum1 = 0;
        sum(root,NULL,NULL,sum1);
        return sum1;
    }
};