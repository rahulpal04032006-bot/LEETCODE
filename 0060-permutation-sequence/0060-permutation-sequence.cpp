class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
       
        while(k-1 >0){
            int pivot = -1;
            for(int i=n-2;i>=0;i--){
                if(v[i] < v[i+1]){
                    pivot = i;
                    break;
                }
            }
            if(pivot == -1){
                reverse(v.begin(),v.end());
            }
            for(int i = n-1;i>=0;i--){
                if(v[i] > v[pivot]){
                    swap(v[i],v[pivot]);
                    break;
                }
            }
            reverse(v.begin()+pivot+1,v.end());
            k--;
        }
        string ans = "";
        for(int i=0;i<v.size();i++){
            ans += to_string(v[i]);
        }
        return ans;
    }
};