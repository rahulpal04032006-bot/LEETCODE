class Solution {
public:
vector<vector<int>>result;
vector<int>temp;
void comb(vector<int>& nums,int i,int k,int n){
    if(temp.size() == k){
        if(n == 0){
            result.push_back(temp);
        }
        return;
    }
    if(i == nums.size()){
        return ;
    }
    comb(nums,i+1,k,n);
    temp.push_back(nums[i]);
    comb(nums,i+1,k,n-nums[i]);
    temp.pop_back();
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        comb(nums,0,k,n);
        return result;
    }
};