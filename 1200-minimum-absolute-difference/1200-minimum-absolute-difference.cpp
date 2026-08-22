class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        int minDiff = INT_MAX;
        for(int i=1;i<n;i++){
            int k = arr[i]-arr[i-1];
            if(k<minDiff){
                minDiff = k;
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }else if( k == minDiff){
                ans.push_back({arr[i-1],arr[i]});
                 
            }
        }
        return ans;
    }
};