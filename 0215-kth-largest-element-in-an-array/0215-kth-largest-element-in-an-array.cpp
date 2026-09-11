class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    map<int,int>m;
    int n = nums.size();
    for(int i=0;i<n;i++){
        m[nums[i]]++;
    }
    for(auto i= m.rbegin();i!=m.rend();i++){
        k -= i->second;
        if(k <= 0){
            return i->first;
        }
    }
    return -1;
    }
};