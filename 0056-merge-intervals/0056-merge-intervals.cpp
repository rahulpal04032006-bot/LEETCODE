class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        int currstartTime = intervals[0][0];
        int currNextTime = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=currNextTime){
                currNextTime = max(currNextTime,intervals[i][1]);  
            }else{
                ans.push_back({currstartTime,currNextTime});
                currstartTime = intervals[i][0];
                currNextTime = intervals[i][1];
            }
        }
        ans.push_back({currstartTime,currNextTime});
        return ans;
    }
};