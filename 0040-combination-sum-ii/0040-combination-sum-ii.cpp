class Solution {
public:
void check(vector<int>& nums,int start,vector<int>& temp,vector<vector<int>>& ans,int target){

if(target == 0){
       ans.push_back(temp);
    return;
}
for(int i = start;i<nums.size();i++){
    if(i>start && nums[i] == nums[i-1]){
        continue;
    }
    if(nums[i] > target){
        break;
    }
    temp.push_back(nums[i]);
    check(nums,i+1,temp,ans,target - nums[i]);
    temp.pop_back();
}
   

}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       vector<int>temp;
       vector<vector<int>>ans;
       check(nums,0,temp,ans,target);
       return ans;
    }
};