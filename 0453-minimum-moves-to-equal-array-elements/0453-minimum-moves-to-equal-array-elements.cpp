class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min1 = INT_MAX;
        for(int i=0;i<n;i++){
            if(min1 > nums[i]){
                min1 = nums[i];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += nums[i] - min1;
        }
        return ans;
    }
};