class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            st.push_back(make_pair(nums[i][0],i));
        }
        sort(st.begin(),st.end());
        vector<int>ans(n,-1);
        for(int i=0;i<nums.size();i++){
            int end = nums[i][1];
            int left = 0;
            int right = st.size() - 1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(st[mid].first  >= end){
                    ans[i] = st[mid].second;
                    right = mid -1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return ans;
    }
};