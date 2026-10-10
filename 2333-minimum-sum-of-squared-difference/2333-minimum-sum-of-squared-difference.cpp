class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long ans = 0;
        long long used = 0;

        for (int x : diff) {
            int val = min(x, low);
            ans += 1LL * val * val;
            used += x - val;
        }

        long long rem = k - used;
        ans -= rem * (2LL * low - 1);

        return ans;
        // int n = nums1.size();
        // long long k =  (k1 + k2);
        // priority_queue<int>pq;
        // for(int i=0;i<n;i++){
        //     pq.push(abs(nums1[i] - nums2[i]));
        // }
        // while(k > 0 && !pq.empty()){
        //     int x = pq.top();
        //     pq.pop();
        //     if(x == 0){
        //         pq.push(0);
        //         break;
        //     }
        //     pq.push(x-1);
        //     k--;
        // }
        // long long ans = 0;
        // while(!pq.empty()){
        //     int x = pq.top();
        //     pq.pop();
        //     ans += 1LL*x*x;
        // }
        // return ans;
        
    }
};