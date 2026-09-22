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
vector<double>ans;
map<int,vector<int>>m;
void avg(TreeNode* root,int i){
    if(root == NULL){
        return;
    }
    m[i].push_back(root->val);
    avg(root->left,i+1);
    avg(root->right,i+1);
}
    vector<double> averageOfLevels(TreeNode* root) {
        avg(root,0);
        for (auto &i : m) {
            double sum = 0;
            for (int x : i.second) {
                sum += x;
            }
            ans.push_back(sum / i.second.size());
        }
        return ans;
    }
};