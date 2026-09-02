class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // Already uniform
        if (!hasOdd || !hasEven)
            return true;

        // Both odd and even exist.
        // We can subtract an opposite-parity number
        // to make the result odd.
        return true;
    }
};