class Solution {
public:
int hist(vector<int>& nums){
    int n = nums.size();
    vector<int>nsl(n);
    vector<int>nsr(n);
    stack<int>st;
    nsl[0] = -1;
    st.push(0);
    for(int i=1;i<n;i++){
        int curr = nums[i];
        while(!st.empty() && curr <= nums[st.top()]){
            st.pop();
        }
        if(st.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    nsr[n-1] = n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        int curr = nums[i];
        while(!st.empty() && curr <= nums[st.top()]){
            st.pop();
        }
        if(st.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = st.top();
        }
        st.push(i);
    }
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans = max(ans,nums[i] * (nsr[i] - nsl[i] -1));
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j] == '0')
                sum = 0;
                else 
                sum++;
                
                prefix[i][j] = sum;

            }
        }
        int maxarea = 0;
        for(int i=0;i<n;i++){
            maxarea = max(maxarea,hist(prefix[i]));
        }
        return maxarea;
    }
};