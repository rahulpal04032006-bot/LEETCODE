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
vector<int>ans;
vector<int>temp;
void largest(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        int max1;
        if(curr == NULL){
            max1 = *max_element(temp.begin(),temp.end());
            ans.push_back(max1);
            temp.clear();
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            temp.push_back(curr->val);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}
    vector<int> largestValues(TreeNode* root) {
        largest(root);
        return ans;
    }
};