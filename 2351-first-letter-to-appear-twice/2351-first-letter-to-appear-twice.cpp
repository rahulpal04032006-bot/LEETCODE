class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>count(26,0);
        char ans;
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a'] == 2){
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};