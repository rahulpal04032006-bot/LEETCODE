class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > max1){
                max1 = nums[i];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max1 - nums[i];
        }
        return ans;
    }
};