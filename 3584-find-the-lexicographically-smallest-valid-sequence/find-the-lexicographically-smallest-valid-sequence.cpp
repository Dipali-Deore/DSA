class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, m);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans;
        bool used = false;
        int k = 0;

        for (int i = 0; i < n && k < m; i++) {

            if (word1[i] == word2[k]) {
                ans.push_back(i);
                k++;
            }
            else if (!used) {
                if (suf[i + 1] <= k + 1) {
                    ans.push_back(i);
                    used = true;
                    k++;
                }
            }
        }

        if (k != m)
            return {};

        return ans;
    }
};