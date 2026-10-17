class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>temp;
        for(int x:nums){
            int sum = 0;
            int val = x;
            while(val > 0){
                sum += val%10;
                val /= 10;
            }
            temp.push_back(make_pair(sum,x));
        }
        sort(temp.begin(),temp.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == temp[i].second)
                continue;

            int j = pos[temp[i].second];

            pos[nums[i]] = j;
            pos[nums[j]] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};