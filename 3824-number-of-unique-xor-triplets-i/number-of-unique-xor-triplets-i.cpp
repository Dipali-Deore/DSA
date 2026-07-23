class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // Special cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Smallest power of 2 greater than n
        int ans = 1;
        while (ans <= n) ans <<= 1;

        return ans;
    }
};