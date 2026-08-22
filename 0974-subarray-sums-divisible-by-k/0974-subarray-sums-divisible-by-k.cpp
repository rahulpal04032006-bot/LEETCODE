class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>freq(k,0);
        freq[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = ((sum%k)+k)%k;
            count += freq[rem];
            freq[rem]++;
        }
       
        return count;
    }
};