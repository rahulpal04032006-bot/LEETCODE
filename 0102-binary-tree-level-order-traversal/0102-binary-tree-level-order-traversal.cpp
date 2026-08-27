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
void level(TreeNode*root){
    vector<int>curr;
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode*temp = q.front();
        q.pop();
          if(temp == NULL){
            ans.push_back(curr);
           curr.clear();
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
              curr.push_back(temp->val);
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        }
      
    }


}
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        level(root);
        return ans;
        
    }
};