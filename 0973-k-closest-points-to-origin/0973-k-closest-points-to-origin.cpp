class Solution {
public:
class Car{
    public:
    int dist;
    vector<int>nums;
    Car(int dist,vector<int>nums){
        this->dist = dist;
        this->nums = nums;
    }
    bool operator < (const Car& obj) const{
        return this->dist > obj.dist;
    }
};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
     vector<Car>cars;
     for(auto& p:points){
        int dist = (p[0]*p[0]) + (p[1]*p[1]);
        cars.push_back(Car(dist,p));
     }
 priority_queue<Car>pq(cars.begin(),cars.end());
     vector<vector<int>>ans;
     for(int i=0;i<k;i++){
        ans.push_back(pq.top().nums);
        pq.pop();
     }
     return ans;
    }
};