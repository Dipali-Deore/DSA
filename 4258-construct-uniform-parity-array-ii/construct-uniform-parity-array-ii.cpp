class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        int mn = nums1[0];

        // If minimum is even,
        // every number must already be even.
        if (mn % 2 == 0) {
            for (int x : nums1) {
                if (x % 2 != 0)
                    return false;
            }
        }

        return true;
    }
};