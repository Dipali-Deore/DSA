class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        // Masks for the three possible groups
        int LEFT   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int MIDDLE = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int RIGHT  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Initially assume every row is completely empty
        int ans = (n - rows.size()) * 2;

        // Process rows having reservations
        for (auto &[row, mask] : rows) {

            bool leftAvailable =
                (mask & LEFT) == 0;

            bool middleAvailable =
                (mask & MIDDLE) == 0;

            bool rightAvailable =
                (mask & RIGHT) == 0;

            if (leftAvailable && rightAvailable) {
                ans += 2;
            }
            else if (leftAvailable || middleAvailable || rightAvailable) {
                ans += 1;
            }
        }

        return ans;
    }
};