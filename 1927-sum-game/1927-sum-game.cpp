class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum = 0,Q = 0;
        for(int i=0;i<n/2;i++){
            if(num[i] == '?'){
              Q++;
            }else{
            sum += num[i]-'0';
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i] == '?'){
                Q--;
            }else{
            sum -= num[i]-'0';
            }
        }
      return Q%2!=0 ||(sum)*2 != -9*(Q);
    }
};