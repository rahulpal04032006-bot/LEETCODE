class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_set<int>dist;
            for(int j=i;j<n;j++){
                dist.insert(nums[j]);
                int s = dist.size();
                ans += s*s;
            }
        }
        return ans;
    }
};