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
TreeNode* arr(vector<int>& nums, int i,int j){
    if(i>j){
        return NULL;
    }
    int st = i;
    int end =j;
    int mid = (st+end)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    if(st == end){
    return root;
    } 
    root->left = arr(nums,i,mid-1);
    root->right = arr(nums,mid+1,end);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
     return  arr(nums,0,nums.size()-1);

    }
};