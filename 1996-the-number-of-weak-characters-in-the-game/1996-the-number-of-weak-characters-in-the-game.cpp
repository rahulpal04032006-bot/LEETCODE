class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        int n = nums.size();
       sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
});

       int max1 = 0;
        int count = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i][1] < max1){
                count++;   
            }
            max1 = max(max1,nums[i][1]);
        }
        return count;
    }
};