class Solution {
public:
    int characterReplacement(string s, int k) {

        int count[26] = {};

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;

            maxFreq = max(maxFreq, count[s[right] - 'A']);

            int windowSize = right - left + 1;

            if (windowSize - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};