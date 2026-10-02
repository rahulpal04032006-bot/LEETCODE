class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>m;
        int x = 0;
        for(int i=0;i<key.size();i++){
            if(m.find(key[i]) == m.end() && key[i] != ' '){
            m[key[i]] = ('a' + x);
            x++;
            }
        }
        string ans = "";
        for(char ch: message){
            if(ch == ' '){
                ans += ' ';
            }else
            ans += m[ch];
        }
        return ans;
    }
};