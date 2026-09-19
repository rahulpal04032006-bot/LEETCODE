class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int,greater<int>>m;
        for(int x:nums){
            m[x] = x;
        }
        auto first = m.begin();
        if(m.size() < 3){
            return first->second;
        }
        advance(first,2);
            return first->second;
        

    }
};