class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int max1 = *max_element(nums.begin(),nums.begin()+i+1);
            int min1 = *min_element(nums.begin()+i,nums.end());
            if((max1 - min1) <= k){
                return i;
            }
        }
        return -1;
    }
};