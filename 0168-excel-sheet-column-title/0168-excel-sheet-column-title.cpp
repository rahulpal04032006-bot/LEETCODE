class Solution {
public:
    string convertToTitle(int n) {
        string part = "";
        while(n>0){
            n--;
            part += (n%26 +'A');
            n /= 26;
        }
        reverse(part.begin(),part.end());
        return part;
    }
};