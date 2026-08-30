class Solution {
public:
void mergeSort(vector<pair<int,int>>& temp,int st,int end,vector<int>& ans){
    if(st >= end){
        return ;
    }
    int mid = st + (end - st)/2;
    mergeSort(temp,st,mid,ans);
    mergeSort(temp,mid+1,end,ans);
    merge(temp,st,mid,end,ans);
}
void merge(vector<pair<int,int>>& temp,int st,int mid,int end,vector<int>& ans){
    vector<pair<int,int>>arr;
    int i = st;
    int j = mid+1;
    int count = 0;
    while(i <= mid && j <= end){
        if(temp[j].first < temp[i].first){
            arr.push_back(temp[j]);
            count++;
            j++;
        }else{
            ans[temp[i].second] += count;
            arr.push_back(temp[i]);
            i++;
        }
    }
       while(i <= mid){
            ans[temp[i].second] += count;
            arr.push_back(temp[i]);
            i++;
        }
        while(j <= end){
            arr.push_back(temp[j]);
            count++;
            j++;
        }
        for(int k = st;k <= end;k++){
            temp[k] = arr[k-st];
        }
}
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        int st = 0,end = n-1;
        mergeSort(temp,st,end,ans);
        return ans;
    }
};