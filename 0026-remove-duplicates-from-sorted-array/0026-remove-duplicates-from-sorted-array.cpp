class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        int left = 1;
        for(int right = 1;right<n;right++){
            if(nums[right] != nums[left-1]){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};