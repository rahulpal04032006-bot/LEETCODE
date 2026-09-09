class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }long long count = 0;
        for(long long i = 1000;i<=n;){
            count += n-i+1;
            if(i > n/1000){
                break;
            }
            i *= 1000;
        }
        return count;
    }
};