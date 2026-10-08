class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {

            if (c == '(') {
                // If depth is 0, this is outermost '('
                if (depth > 0) {
                    ans += c;
                }

                depth++;
            }

            else { // c == ')'
                depth--;

                
                if (depth > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};