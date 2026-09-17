class Solution {
public:
    string longestPalindrome(string s) {
     int n = s.size();
     int st = 0;
     int maxlen = 1;
     for(int i=0;i<n;i++){
        int l , r;
        l = r = i;
        while(l >=0 && r < n && s[l] == s[r]){
            if((r-l+1)>maxlen){
                maxlen = r - l +1;
                st = l;
            }
            l--;
            r++;
        }
          l = i;
          r = i+1;
        while(l >=0 && r < n && s[l] == s[r]){
            if((r-l+1)>maxlen){
                maxlen = r - l +1;
                st = l;
            }
            l--;
            r++;
        }
     }
    
     
    
     return s.substr(st,maxlen);
    }
};