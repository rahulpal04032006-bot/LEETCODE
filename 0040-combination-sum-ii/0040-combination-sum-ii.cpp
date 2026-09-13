class Solution {
public:
void check(vector<int>& nums,int i,vector<int>& temp,vector<vector<int>>& ans,int target){

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i == nums.size() || target < 0) {
            return;
        }

        // TAKE
        temp.push_back(nums[i]);
        check(nums, i + 1, temp, ans, target - nums[i]);
        temp.pop_back();
        // NOT TAKE
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        check(nums, i + 1, temp, ans, target);
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       vector<int>temp;
       vector<vector<int>>ans;
       check(nums,0,temp,ans,target);
       return ans;
    }
};