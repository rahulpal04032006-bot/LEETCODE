class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 || sum > 9*num){
            return "";
        }
        string ans = "";
        for(int i=0;i<num;i++){
            int dig = min(9,sum);
                ans += to_string(dig);
                sum -= dig;
            
        }
        return ans;
    }
};