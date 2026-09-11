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
int ans = INT_MAX;
TreeNode* nxt = NULL;
void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(nxt != NULL){
        ans = min(ans,root->val - nxt->val);
    }
    nxt = root;
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
     inorder(root);
     return ans;
    }
};