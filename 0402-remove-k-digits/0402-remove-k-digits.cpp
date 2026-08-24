class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        int i = 0;
        for(char ch:num){
            while(!ans.empty() && k>0 && ans.back() > ch){
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        int j = 0;
        while(j<ans.size() && ans[j] == '0'){
            j++;
        }
        ans = ans.substr(j);
        if(ans.size() == 0){
            return "0";
        }
            return ans;
    }
};