class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;
        int n=temperatures.size();
        vector<int>ans(n,0);
        int maxi=INT_MIN;

        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()])
            {
                int index=stk.top();
                stk.pop();

                ans[index]=i-index;
            }
            stk.push(i);
        }

        return ans;
    }
};