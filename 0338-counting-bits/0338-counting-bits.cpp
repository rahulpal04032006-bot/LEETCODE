class Solution {
public:
int count(int i){
    if(i == 0)
    return 0;
    return count(i/2) + (i%2);
}
    vector<int> countBits(int n) {
        vector<int>nums(n+1);
        for(int i=0;i<=n;i++){
            nums[i] = count(i);
        }
        return nums;
    }
};