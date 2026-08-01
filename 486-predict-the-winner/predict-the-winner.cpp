class Solution {
public:
    vector<vector<int>> memo;

    int solve(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];

        if (memo[left][right] != INT_MIN)
            return memo[left][right];

        int pickLeft = nums[left] - solve(nums, left + 1, right);
        int pickRight = nums[right] - solve(nums, left, right - 1);

        return memo[left][right] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n, INT_MIN));

        return solve(nums, 0, n - 1) >= 0;
    }
};