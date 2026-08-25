class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min1 = arrays[0][0];
        int max1 = arrays[0].back();
        int ans = 0;
        for(int i=1;i<n;i++){
            int currMin = arrays[i][0];
            int currMax = arrays[i].back();
            ans = max(ans,abs(currMax-min1));
            ans = max(ans,abs(max1-currMin));

            min1 = min(min1,currMin);
            max1 = max(max1,currMax);

        }
        return ans;
    }
};