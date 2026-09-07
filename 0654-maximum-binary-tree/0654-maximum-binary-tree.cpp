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
TreeNode* tree(vector<int>& nums,int st,int end){
    if(st > end){
        return NULL;
    }
    long long max1 = INT_MIN;
    int mid;
    for(int i=st;i<=end;i++){
        if(nums[i] > max1){
            max1 = nums[i];
            mid = i;
        }
    }
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = tree(nums,st,mid-1);
    root->right = tree(nums,mid+1,end);
return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return tree(nums,0,nums.size()-1);
       
    }
};