class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char ch : s) {

            if (ch == '(') {
                // Save the current string
                st.push(current);

                // Start a new substring
                current = "";
            }
            else if (ch == ')') {
                // Reverse the current substring
                reverse(current.begin(), current.end());

                // Add it to the previous string
                current = st.top() + current;
                st.pop();
            }
            else {
                // Normal character
                current += ch;
            }
        }

        return current;
    }
};