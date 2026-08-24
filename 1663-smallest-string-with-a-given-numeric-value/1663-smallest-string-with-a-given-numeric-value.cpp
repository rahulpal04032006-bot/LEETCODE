class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        int extra = k -n;
        for(int i = n-1;i>=0;i--){
            int add =min(extra,25);
            ans[i] += add;
            extra -= add;
            if(extra == 0)
            break;
        }
        return ans;
    }
};