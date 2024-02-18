class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='{' || ch=='('|| ch=='[')
            {// open bracket
             st.push(ch);

            }
            else
            {
                // closing bracket hoga
                // is case ka hamesa dyan dena
               // pop krne sey dekho kahi string empty toh nhi hei
                if(!st.empty())
                {
                    
                
                     if(ch==')' && st.top()=='(')
                    {
                        // match kr gaya
                    st.pop();
                    }
                    else if(ch==']' && st.top()=='[')
                    {
                    st.pop();
                    }
                    else if(ch=='}' && st.top()=='{')
                    {
                    st.pop();
                    }
                    else
                    {
                        // nhi kr match
                        return false;
                    }

                }
                else
                {
                    // stack empty hei
                    return false;
                }
                
            }
        }
        if(st.size()==0)
        {
            // sare operation kei baad string khale hogye
            // valid parenthesis
            return true;
        }
        else
        {
            return false;
        }
        
    }
};