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
void inorder(TreeNode* root,vector<int>& nums1){
    if(root == NULL){
        return ;
    }
    inorder(root->left,nums1);
    nums1.push_back(root->val);
  
    inorder(root->right,nums1);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1;
        vector<int>nums2;
        vector<int>nums;
        inorder(root1,nums1);
        inorder(root2,nums2);
       merge(nums1,nums2,nums);
       return nums;

    }
    private:
   void merge(vector<int>& nums1,vector<int>& nums2,vector<int>& nums){
    int i = 0,j =0;
    
    while(i<nums1.size() && j< nums2.size()){
        if(nums2[j] < nums1[i]){
         nums.push_back(nums2[j]);
            j++; 
        }else{
            nums.push_back(nums1[i]);
            i++;
        }
    }
    while(i<nums1.size()){
        nums.push_back(nums1[i]);
        i++;
    }
    while(j < nums2.size()){
        nums.push_back(nums2[j]);
        j++;
    }
   }
};