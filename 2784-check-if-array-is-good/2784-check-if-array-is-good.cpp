class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int count[201];
        for(int num : nums){
            count[num]++;
        }
        if(count[n-1] != 2){
            return false;
        }else{
        for(int i=1;i<n-1;i++){
            if(count[i] != 1){
                return false;

            }
        }
        }
return true;
    }
};