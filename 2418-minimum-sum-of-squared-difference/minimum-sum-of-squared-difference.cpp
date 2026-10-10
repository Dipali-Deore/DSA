
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> diff(nums1.size());

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                needed += max(0, d - mid);
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > limit) {
                used += d - limit;
                d = limit;
            }
            ans += 1LL * d * d;
        }

        long long remaining = k - used;

        for (int i = 0; i < diff.size() && remaining > 0; i++) {
            if (diff[i] >= limit && diff[i] > 0) {
                ans -= 2LL * limit - 1;
                remaining--;
            }
        }

        return ans;
    }
};
