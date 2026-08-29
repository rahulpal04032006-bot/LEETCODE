class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool>temp(256,false);
        for(int i=0;i<jewels.size();i++){
            temp[jewels[i]] = true;
        }
        int count = 0;
        for(int i=0;i<stones.size();i++){
            if(temp[stones[i]]){
                count++;
            }
        }
        return count;
    }
};