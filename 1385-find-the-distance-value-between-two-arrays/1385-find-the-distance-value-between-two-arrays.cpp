class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int count = 0;
        int m = arr2.size();
        for(int i=0;i<n;i++){ 
        bool ist = true;
            for(int j = 0;j<m;j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                ist = false;
                break;
                }

            }
            if(ist)
            count++;
        }
        return count;
    }
};