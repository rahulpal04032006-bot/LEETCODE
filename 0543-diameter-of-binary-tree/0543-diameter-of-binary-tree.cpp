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
pair<int,int>diameter(TreeNode*root){
    if(root == NULL){
        return {0,0};
    }
    pair<int,int> leftInfo = diameter(root->left);
    pair<int,int> rightInfo = diameter(root->right);
    int currDia = leftInfo.second +rightInfo.second;
    int finalDia = max(max(leftInfo.first,rightInfo.first),currDia);
    int currH =  max(leftInfo.second,rightInfo.second)+1;
    return {finalDia,currH};
}
    int diameterOfBinaryTree(TreeNode* root) {

       return diameter(root).first;
        
    }
};