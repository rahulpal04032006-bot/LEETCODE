class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int reverse = 26 - (s[i] - 'a');
            ans += (i+1)*reverse;
        }
        return ans;
    }
};