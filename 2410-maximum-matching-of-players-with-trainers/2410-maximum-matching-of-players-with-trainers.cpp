class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int left = 0;
        int right = 0;
        int count = 0;
        while(left < players.size() && right < trainers.size()){
            if(players[left] <= trainers[right]){
                count++;
                left++;
            }
            right++;
        }
        return count;
    }
};