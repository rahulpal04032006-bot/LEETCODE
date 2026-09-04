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
int x;
void maxa(TreeNode* root,int maxNode,int minNode){
    if(root == NULL){
        return;
    }
    maxNode = max(maxNode,root->val);
    minNode = min(minNode,root->val);
    x = max(x,max(abs(root->val - maxNode),abs(root->val - minNode)));
   maxa(root->left,maxNode,minNode);
   maxa(root->right,maxNode,minNode);
}
    int maxAncestorDiff(TreeNode* root) {
        maxa(root,root->val,root->val);
        return x;
    }
};