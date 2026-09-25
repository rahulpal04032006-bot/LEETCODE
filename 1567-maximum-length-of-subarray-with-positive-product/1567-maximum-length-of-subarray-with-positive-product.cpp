class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int neg = 0;
        int left = 0;
        int firstneg = -1;
        for(int right = 0;right<n;right++){
            if(nums[right] == 0){
                left = right + 1;
                firstneg = -1;
                neg =  0;
                continue;
            }
            if(nums[right] < 0){
                neg++;
                if(firstneg == -1){
                    firstneg = right;
                }
            }
            if(neg % 2 == 0){
                count = max(count,right - left + 1);
            }else{
                count = max(count,right-firstneg);
            }
            
        }
        return count;
    }
};