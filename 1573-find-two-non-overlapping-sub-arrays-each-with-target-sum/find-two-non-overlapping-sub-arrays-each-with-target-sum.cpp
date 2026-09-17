class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n, INF);

        int left = 0;
        int sum = 0;

        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Found a subarray with sum = target
            if (sum == target) {

                int len = right - left + 1;

                // Combine with the best previous subarray
                if (left > 0 && dp[left - 1] != INF) {
                    ans = min(ans, dp[left - 1] + len);
                }

                // Current subarray becomes the best
                if (right == 0)
                    dp[right] = len;
                else
                    dp[right] = min(dp[right - 1], len);
            }
            else {
                // No new subarray ending here
                if (right > 0)
                    dp[right] = dp[right - 1];
            }
        }

        return ans == INF ? -1 : ans;
    }
};