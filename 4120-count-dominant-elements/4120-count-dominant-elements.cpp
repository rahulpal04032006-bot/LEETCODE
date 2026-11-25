class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(nums.size() == 1){
            return 1;
        }
        if(nums[0] >= nums[1]){
            ans++;
        }
        if(nums[n-1] >= nums[n-2]){
            ans++;
        }
        if(n > 2){
            for(int i=1;i<n-1;i++){
                if(2LL * nums[i] >= 1LL * (nums[i-1] + nums[i+1])){
                    ans++;
                }
            }
        }
        return ans;
    
    }
};