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
long long sum = 0;
long long ans = 0;
long long pro(TreeNode* root,long long sum){
    if(root == NULL){
        return 0;
    }
   long long left = pro(root->left,sum);
   long long right = pro(root->right,sum);
   long long subtreesum = root->val + left + right;
   ans = max(ans,(sum - subtreesum)* subtreesum);
   return subtreesum;
}
long long totalsum(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return totalsum(root->left) + totalsum(root->right) + root->val;
}
    int maxProduct(TreeNode* root) {
        long long sum1 = totalsum(root);
       pro(root,sum1); 
       return ans %  1000000007;
    }
};