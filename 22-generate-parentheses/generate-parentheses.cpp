
class Solution {
public:
    void solve(int open, int close, int n, string curr,
               vector<string>& ans) {
        
        // Base case: used all n pairs
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still have opening brackets
        if (open < n) {
            solve(open + 1, close, n, curr + '(', ans);
        }

        // Add ')' only if it won't make the string invalid
        if (close < open) {
            solve(open, close + 1, n, curr + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};
