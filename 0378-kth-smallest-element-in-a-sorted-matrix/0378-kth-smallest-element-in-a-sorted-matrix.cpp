class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int>nums(n*n);
        for(int i=0;i<n*n;i++){
            nums[i] = matrix[i/n][i%n]; 
        }
        sort(nums.begin(),nums.end());
        return nums[k-1];
    }
};