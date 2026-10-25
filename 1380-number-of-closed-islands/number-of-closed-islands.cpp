
class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;

        if (grid[r][c] == 1)
            return true;

        grid[r][c] = 1;

        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
