class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        
        int n = s.size();

        // Step 1: Count frequency of each character
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Step 2: Check whether a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = char('a' + i);
            }
        }

        // More than one odd-frequency character
        // means palindrome is impossible
        if (odd > 1) {
            return "";
        }

        // Step 3: Build frequency for the first half
        vector<int> halfCnt(26, 0);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string best = "";

        // Step 4:
        // Try every position where our answer
        // becomes strictly greater than target.
        for (int breakPos = 0; breakPos < halfLen; breakPos++) {

            vector<int> remaining = halfCnt;
            string left = "";

            bool possible = true;

            // Keep the prefix equal to target
            for (int i = 0; i < breakPos; i++) {

                int c = target[i] - 'a';

                // We don't have this character
                if (remaining[c] == 0) {
                    possible = false;
                    break;
                }

                left += target[i];
                remaining[c]--;
            }

            if (!possible) {
                continue;
            }

            // At breakPos, choose the smallest character
            // that is greater than target[breakPos]
            int targetChar = target[breakPos] - 'a';

            int chosen = -1;

            for (int c = targetChar + 1; c < 26; c++) {

                if (remaining[c] > 0) {
                    chosen = c;
                    break;
                }
            }

            // No character can make us greater here
            if (chosen == -1) {
                continue;
            }

            // Add the character that makes us greater
            left += char('a' + chosen);
            remaining[chosen]--;

            // Fill the rest with the smallest possible characters
            for (int c = 0; c < 26; c++) {

                while (remaining[c] > 0) {
                    left += char('a' + c);
                    remaining[c]--;
                }
            }

            // Step 5: Construct the palindrome
            string candidate = left;

            // Add middle character for odd length
            if (n % 2 == 1) {
                candidate += mid;
            }

            // Add reverse of left half
            string rev = left;
            reverse(rev.begin(), rev.end());

            candidate += rev;

            // Keep the smallest valid answer
            if (candidate > target) {

                if (best.empty() || candidate < best) {
                    best = candidate;
                }
            }
        }

        // Step 6:
        // Check the case where the entire first half
        // is exactly equal to target's first half.
        vector<int> remaining = halfCnt;
        string left = "";

        bool possible = true;

        for (int i = 0; i < halfLen; i++) {

            int c = target[i] - 'a';

            if (remaining[c] == 0) {
                possible = false;
                break;
            }

            left += target[i];
            remaining[c]--;
        }

        if (possible) {

            string candidate = left;

            // Middle character
            if (n % 2 == 1) {
                candidate += mid;
            }

            // Reverse left half
            string rev = left;
            reverse(rev.begin(), rev.end());

            candidate += rev;

            // Check if it is strictly greater than target
            if (candidate > target) {

                if (best.empty() || candidate < best) {
                    best = candidate;
                }
            }
        }

        return best;
    }
};