class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Try every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {

            long long currentLCM = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    currentLCM = lcm(currentLCM, coins[i]);

                    // LCM is already greater than x,
                    // so it contributes nothing.
                    if (currentLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long multiples = x / currentLCM;

            if (bits % 2 == 1)
                count += multiples;
            else
                count -= multiples;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};