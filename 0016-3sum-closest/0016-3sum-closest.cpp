class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int close = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<n-2;i++){
            int x = nums[i];
            int j = i+1;
            int k = n-1;   
            while(j < k){
                sum = x + nums[j] + nums[k];
                if(abs(sum - target) < abs(close - target)){
                    close = sum;
                }
                if(sum == target){
                    return sum;
                }
                if(sum > target){
                    k--;
                }else{
                    j++;
                }
        }
        }
       return close;
    }
};