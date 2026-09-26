class Solution {
public:
    bool canConstruct(string s, string p) {
        map<char,int>m1;
        map<char,int>m2;
        for(char ch : s){
            m1[ch]++;
        }
        for(char ch : p){
            m2[ch]++;
        }
       for(auto& i: m1){
        if(m2[i.first] < i.second){
            return false;
        }
       }
       return true;
    }
};