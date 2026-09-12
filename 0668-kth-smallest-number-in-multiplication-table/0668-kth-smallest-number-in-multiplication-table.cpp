class Solution {
public:
    int findKthNumber(int m, int n, int k) {
      int st = 1;
      int end = m*n;
      while(st < end){
        int mid = st + (end - st)/2;
        int count = 0;
        for(int i=1;i<=m;i++){
            count += min(n,mid/i);
        }
        if(count >= k){
            end = mid;
        }else{
            st = mid+1;
        }
      }
      return st;
    }
};