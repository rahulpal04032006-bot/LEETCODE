class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        string s;
        int ans = INT_MAX;
        for(int i=0;i<n-1;i+=2){
            s = to_string(nums[i]) + to_string(nums[i+1]);
            int  x = stoi(s);
            ans = min(ans,x);
        }
        return ans;
    }
};