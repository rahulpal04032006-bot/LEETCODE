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
int sum = 0;
int totalSum = 0;
void sum1(TreeNode* root){
if(root == NULL){
    return ;
}
sum = sum*10 + root->val;
if(root->left == NULL && root->right == NULL){
    totalSum += sum;
}
sum1(root->left);
sum1(root->right);
sum /= 10;
}
    int sumNumbers(TreeNode* root) {
        sum1(root);
        return totalSum;
    }
};