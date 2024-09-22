class Solution {
public:
    int longestValidParentheses(string s) {
        // answer mein int chaye toh muje bracket sey related koi integer store krna hoga
        stack<int> st;
        st.push(-1);
        int max_length=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                   
                  int len=i-st.top();
                  max_length=max(len,max_length);
                }
            }
        }
        return max_length;

    }
};