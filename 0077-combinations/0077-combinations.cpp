class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
void comb(vector<int>& nums,int i,int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i == nums.size()){
            return; 
            }
       for(int j = i;j<nums.size();j++){
        temp.push_back(nums[j]);
        comb(nums,j+1,k);
        temp.pop_back();
       }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        comb(nums,0,k);
        return ans;
    }
};