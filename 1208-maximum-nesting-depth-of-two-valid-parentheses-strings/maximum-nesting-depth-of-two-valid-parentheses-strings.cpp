class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>vt;
        int res=-1;
        // stack<char>stk;
        for(int i=0;i<seq.length();i++)
        {
            if(seq[i]=='(')
            {
                res++;
                // stk.push(seq[i]);
                vt.push_back(res%2);
            }
            else
            {
                
                // stk.pop();
                vt.push_back(res%2);
                res--;
            }
        }

        return  vt;
        
    }
};