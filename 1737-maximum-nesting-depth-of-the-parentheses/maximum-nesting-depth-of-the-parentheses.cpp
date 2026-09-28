class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int ans=INT_MIN;

        stack<int>stk;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('){
                stk.push(s[i]);
                res++;
            }
            else if(s[i]==')')
            {
                stk.pop();
                res--;
            }
            ans=max(ans,res);
        }
        return ans;

    }
};