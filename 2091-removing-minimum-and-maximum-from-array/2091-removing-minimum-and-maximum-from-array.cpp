class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int lowidx = 0,highidx = 0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[lowidx]){
                lowidx = i;
            }
            if(nums[i] > nums[highidx]){
                highidx = i;
            }
        }
        int low = min(lowidx,highidx);
        int high = max(lowidx,highidx);

        int st = high + 1;
        int end = n - low;
        int both = (low+1) + (n-high);
        return min({st,end,both});
       
    }
};