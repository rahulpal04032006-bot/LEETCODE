class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int x:s){
            if(s.count(x-1) == 0){
                int curr = x;
                int length = 1;
                while(s.count(curr+1)){
                curr++;
                length++;
            }
             ans = max(ans,length);
            }
          
           
        }
        
return ans;
        
    }
};