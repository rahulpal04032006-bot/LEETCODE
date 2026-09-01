class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       vector<int>count(51,0);
       for(int i=0;i<nums.size();i++){
        count[nums[i]]++;
       }   
       int ans = 0;
       for(int i =1;i<51;i++){
        if(count[i] == 2){
            ans ^= i;
        }
       } 
       return ans;  
    }
};