class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = -1;

        bool ascending = true;
        bool descending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
            }

            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n) {
                ascending = false;
            }

            if (next != (nums[i] + n - 1) % n) {
                descending = false;
            }
        }

        if (ascending) {
            return min(zero, n - zero + 2);
        }

        if (descending) {
            int reversedZero = n - 1 - zero;
            return min(reversedZero, n - reversedZero) + 1;
        }

        return -1;
    }
};