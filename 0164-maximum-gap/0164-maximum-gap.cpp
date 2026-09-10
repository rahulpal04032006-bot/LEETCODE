class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        int ans = 0;
        int prev = *s.begin();
        for(auto i: s){
            ans = max(ans,i-prev);
            prev = i;
        }
        return ans;
    }
};