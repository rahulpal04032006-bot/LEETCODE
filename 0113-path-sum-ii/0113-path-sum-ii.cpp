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
vector<vector<int>>ans;
vector<int>temp;
void path(TreeNode* root,int target,int sum){
    if(root == NULL){
        return ;
    }
    sum += root->val;
    temp.push_back(root->val);
    if(sum == target && root->left == NULL && root->right == NULL){
        ans.push_back(temp);
    }
    path(root->left,target,sum);
    path(root->right,target,sum);
    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path(root,targetSum,0);
        return ans;
    }
};