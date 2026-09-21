class Solution {
public:
 unordered_map<int,string>m = {
            {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        };
        vector<string>ans;
        void help(string digits,int idx,string curr){
            if(idx == digits.size()){
                ans.push_back(curr);
                return;
            }
            int digit = digits[idx]-'0';
            string part = m[digit];
            for(char ch:part){
                curr.push_back(ch);
                help(digits,idx+1,curr);
                curr.pop_back();
            }
        }
    vector<string> letterCombinations(string digits) {
       if(digits.size() == 0){
        return {};
       }
       string curr = "";
       help(digits,0,curr);
       return ans;
    }
};