class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       vector<pair<int,int>>v;
       int n = nums.size();
       for(int i=0;i<n;i++){
        v.push_back({nums[i],i});
       }
       sort(v.begin(),v.end(),[](auto& a,auto& b){
        return a.first < b.first;
       });
       int st = 0;
       while(st < n){
        int end = st;
        while(end + 1 < n && abs(v[end].first - v[end+1].first) <= limit){
            end++;
        }
        vector<int>idx;
        for(int i=st;i<=end;i++){
            idx.push_back(v[i].second);
        }
        sort(idx.begin(),idx.end());
        for(int i=0;i<idx.size();i++){
            nums[idx[i]] = v[st + i].first; 
        }
        st = end +1;
       }
      return nums;
    }
};