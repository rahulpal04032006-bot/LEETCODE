class Solution {
public:
vector<string>ans;
void create(int open,int close,string s,int n){
    if(close > open){
        return;
    }
    if(open == n && close == n){
        ans.push_back(s);
        return ;
    }
    if(open < n){
        create(open + 1,close,s + "(",n);
    }
    if(close < open){
        create(open,close+1,s+")",n);
    }
    return;

}
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;
        create(open,close,s,n);
        return ans;
    }
};