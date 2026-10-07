class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int maxf = 0;
        int ans = 0;
        int count[26] = {0};
        for(int right = 0;right < n;right++){
            count[s[right] - 'A']++;
            
            maxf = max(maxf,count[s[right] - 'A']);

            while(right - left + 1 > k + maxf){
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans,right-left+1);
        }

        return ans;
    }
};