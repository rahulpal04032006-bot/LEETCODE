class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& nums) {
        int m = nums.size();
      
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j = i+1;j<m;j++){
                if(max(nums[i][0],nums[j][0]) <= min(nums[i][1],nums[j][1])){
                    count++;
                }
            }
        }
        return count;
    }
};