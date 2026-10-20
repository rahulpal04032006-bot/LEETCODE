class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int end = n-1;
        int maxarea = INT_MIN;
        while(st < end){
            int width = end - st;
            int minh = min(height[st],height[end]);
            int area = width*minh;
            maxarea = max(maxarea,area);
            if(height[st] < height[end]){
                st++;
            }else{
                end--;
            }
        }
        return maxarea;
    }
};