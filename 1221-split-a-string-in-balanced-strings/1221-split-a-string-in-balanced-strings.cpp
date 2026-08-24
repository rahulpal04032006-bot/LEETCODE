class Solution {
public:
    int balancedStringSplit(string s) {
        int right = 0 ;
        int count = 0;
        int ans = 0;
        while(right < s.size()){
            if(s[right] == 'R'){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                ans++;
            }
            right++;
        }
        return ans;
    }
};