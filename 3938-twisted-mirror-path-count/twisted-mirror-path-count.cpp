class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int N = m * n;

        auto id = [n](int r, int c) {
            return r * n + c;
        };

       
        vector<int> reachR(N, -1), reachD(N, -1);

     
        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                int cur = id(r, c);

                if (grid[r][c] == 0) {
                    reachR[cur] = reachD[cur] = cur;
                } else {
                  
                    if (r + 1 < m)
                        reachR[cur] = reachD[id(r + 1, c)];

                    if (c + 1 < n)
                        reachD[cur] = reachR[id(r, c + 1)];
                }
            }
        }

        vector<int> dp(N, 0);
        dp[0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int cur = id(r, c);
                if (grid[r][c] == 1 || dp[cur] == 0)
                    continue;

                if (c + 1 < n) {
                    int to = reachR[id(r, c + 1)];
                    if (to != -1)
                        dp[to] = (dp[to] + dp[cur]) % MOD;
                }

                if (r + 1 < m) {
                    int to = reachD[id(r + 1, c)];
                    if (to != -1)
                        dp[to] = (dp[to] + dp[cur]) % MOD;
                }
            }
        }

        return dp[id(m - 1, n - 1)];
    }
};