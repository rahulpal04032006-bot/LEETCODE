class Solution {
public:
set<vector<int>>s;
void combination(vector<int>& nums,int i,vector<int>& temp,vector<vector<int>>& ans,int target){
    int n = nums.size();
    if(i == n || target < 0){
        return;
    }
    if(target == 0){
        if(s.find(temp) == s.end()){
            ans.push_back(temp);
            s.insert(temp);
        }
        return;
    }
    temp.push_back(nums[i]);
    combination(nums,i+1,temp,ans,target-nums[i]);// for first choice only one choice
    combination(nums,i,temp,ans,target-nums[i]);// multiple choice of an element
    temp.pop_back();
    combination(nums,i+1,temp,ans,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        combination(nums,0,temp,ans,target);
        return ans;
    }
};