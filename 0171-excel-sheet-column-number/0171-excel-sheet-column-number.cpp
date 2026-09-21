class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() == 1){
            return (s[0]-'A') + 1;
        }
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans = ans*26 + ((s[i]-'A')+1);
        }
        return ans;
    }
};