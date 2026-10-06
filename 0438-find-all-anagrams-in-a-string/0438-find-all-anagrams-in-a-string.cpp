class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size() > s.size()){
            return ans;
        }
        int countp[26] = {0};
        int counts[26] = {0};
        for(char ch : p){
            countp[ch-'a']++;
        }
        int k = p.size();
        for(int i=0;i<k;i++){
            counts[s[i]-'a']++;
        }
        for(int i=0;i<=s.size()-k;i++){
            bool ist = true;
            for(int j = 0;j<26;j++){
                if(countp[j] != counts[j]){
                    ist = false;
                    break;
                }
            }
            if(ist){
                ans.push_back(i);
            }
            if(i+k < s.size()){
                counts[s[i]-'a']--;
                counts[s[i+k]-'a']++;
            }
        }

        return ans;
    }
};