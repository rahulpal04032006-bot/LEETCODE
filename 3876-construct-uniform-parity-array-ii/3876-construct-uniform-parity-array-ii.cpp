class Solution {
public:
    bool uniformArray(vector<int>& nums1) {  
      int n = nums1.size();
      sort(nums1.begin(),nums1.end());
      int target = nums1[0]%2;
      int j =0;
      for(int i=1;i<n;i++){
        if(nums1[i] % 2 == target){
            continue;
        }
        if(target == 1){
            if(nums1[i] - nums1[0] >= 1 && (nums1[i] - nums1[0]) %2 == target){
                continue;
            }
        }
        return false;
      }  
      return true; 
    }
};