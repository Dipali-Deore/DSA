class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(char ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stk.push(ch);
            }
            else{
                

                if(stk.empty())
                {
                    return false;
                }
                char c=stk.top();

                if((ch==')' && c=='(') || (c=='{' && ch=='}') || (ch==']' && c=='['))
                {
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }

        return stk.empty();
    }
};