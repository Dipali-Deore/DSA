class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>stk;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" ||  tokens[i]=="*" || tokens[i]=="/"){
                int st1=stk.top();
                stk.pop();
                int st2=stk.top();
                stk.pop();

                if(tokens[i]=="+")
                {
                    stk.push(st1+st2);
                }
                else if(tokens[i]=="-")
                {
                    stk.push(st2-st1);
                }
                else if(tokens[i]=="*")
                {
                    stk.push(st1*st2);
                }
                else{
                    stk.push(st2/st1);
                }


            }
            else
            {
                stk.push(stoi(tokens[i]));

                
            }

    
        }
        return stk.top();
        
    }
};