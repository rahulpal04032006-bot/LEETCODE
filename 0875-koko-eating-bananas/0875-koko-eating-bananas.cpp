class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min1 = 1;
        int max1 = *max_element(piles.begin(),piles.end());
        while(min1 < max1){
            int mid = min1 + (max1 - min1)/2;
            long long hour = 0;
            for(int pile:piles){
                hour += (pile+mid-1)/mid;
            }
            if(hour <= h){
                max1 = mid;
            }else{
                min1 = mid+1;
            }
        }
        return min1;
    }
};