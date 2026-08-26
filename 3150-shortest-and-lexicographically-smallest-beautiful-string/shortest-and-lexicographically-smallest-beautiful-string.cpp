class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        if (pos.size() < k)
            return "";

        string ans = "";

        for (int i = 0; i + k <= pos.size(); i++) {
            int left = pos[i];
            int right = pos[i + k - 1];

            string cur = s.substr(left, right - left + 1);

            if (ans.empty() ||
                cur.size() < ans.size() ||
                (cur.size() == ans.size() && cur < ans)) {
                ans = cur;
            }
        }

        return ans;
    }
};