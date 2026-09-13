class Solution {
public:
bool pali(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
    return s == s1;
}
void ispali(string s,vector<string>& temp,vector<vector<string>>& ans){
    if(s.size() == 0){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part = s.substr(0,i+1);
        if(pali(part)){
            temp.push_back(part);
            ispali(s.substr(i+1),temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        ispali(s,temp,ans);
        return ans;
    }
};