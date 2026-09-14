class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = 0;
        int end = nums.size()-1;
        int mid = st+(end-st)/2;
        int count = 0;
        for(int i=0;i<mid;i++){
            count += nums[mid]-nums[i];
        }
        for(int i = mid+1;i<nums.size();i++){
            count += nums[i]-nums[mid];
        }
        return count;
    }
};