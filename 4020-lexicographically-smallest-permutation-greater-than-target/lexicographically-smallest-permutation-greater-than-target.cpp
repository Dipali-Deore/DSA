class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Try to keep the character equal to target[i]
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // We cannot match target[i].
            // First, try to make THIS position greater.
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    // Fill remaining positions with
                    // smallest possible characters.
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }

            // No larger character is possible at current position.
            // So we must backtrack.
            while (!ans.empty()) {

                int prev = ans.back() - 'a';
                ans.pop_back();

                // Restore the character we actually used.
                freq[prev]++;

                // Try to make this previous position larger.
                for (int c = prev + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        ans += char('a' + c);
                        freq[c]--;

                        // Fill the rest in sorted order.
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We matched target completely.
        // Equal is not allowed, so backtrack.
        while (!ans.empty()) {

            int prev = ans.back() - 'a';
            ans.pop_back();

            freq[prev]++;

            // Try a larger character at this position.
            for (int c = prev + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    // Fill remaining characters in sorted order.
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};