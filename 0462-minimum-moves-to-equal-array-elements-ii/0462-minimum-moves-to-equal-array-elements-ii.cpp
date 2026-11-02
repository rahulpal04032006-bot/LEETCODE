class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        sort(nums.begin(),nums.end());
        int mid = st + (end - st)/2;
        int ans = 0;
        for(int i=0;i<mid;i++){
            ans += nums[mid] - nums[i];
        }
        for(int i=mid+1;i<n;i++){
            ans += nums[i] - nums[mid];
        }
        return ans;   
    }
};