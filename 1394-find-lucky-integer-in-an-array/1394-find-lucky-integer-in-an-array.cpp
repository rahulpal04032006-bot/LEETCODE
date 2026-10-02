class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count[501] = {0};
        for(int x: arr){
            count[x]++;
        }
        for(int i=500;i>0;i--){
            if(i == count[i]){
                return i;
                break;
            }
        }
        return -1;
    }
};