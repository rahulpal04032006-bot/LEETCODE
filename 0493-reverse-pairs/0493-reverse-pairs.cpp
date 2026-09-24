class Solution {
public:
int count = 0;
void merging(vector<int>& nums,int st,int mid,int end){
    int j = mid+1;
    for(int i=st;i<=mid;i++){
        while(j<=end && (long long)nums[i] > 2LL*nums[j]){
            j++;
        }
        count += j - (mid+1);
    }
    int i = st;
    j = mid+1;
    vector<int>temp;
    while(i <= mid && j <= end){
       if(nums[i] < nums[j]){
        temp.push_back(nums[i]);
        i++;
       }else{
        temp.push_back(nums[j]);
        j++;
       }
    }
    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }
      while( j<= end){
        temp.push_back(nums[j]);
        j++;
    }
    for(int k = st;k<=end;k++){
        nums[k] = temp[k-st];
    }
}
void merge(vector<int>& nums,int st,int end){
    if(st >= end){
        return;
    }
    int mid = st + (end - st)/2;
    merge(nums,st,mid);
    merge(nums,mid+1,end);
    merging(nums,st,mid,end);
}
    int reversePairs(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return count;
    }
};