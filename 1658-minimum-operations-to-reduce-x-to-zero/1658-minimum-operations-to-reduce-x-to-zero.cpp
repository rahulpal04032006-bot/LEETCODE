class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = 0;
        for(int i=0;i<nums.size();i++){
            totalsum += nums[i];
        }
        int target = totalsum - x;
        int i =0;
        int sum = 0;
        int length = -1;
        for(int j=0;j<nums.size();j++){
            sum += nums[j];
            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }
            if(sum == target){
                length = max(length,j-i+1);
            }
        }
        if(length == -1){
            return -1;
        }
        return nums.size() - length;
    
    }
};