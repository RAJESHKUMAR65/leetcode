class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length()==1) return s;
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!st.empty()&&s[i]==st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans; 
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans.push_back(ch);
        }

        reverse(ans.begin(),ans.end());
        return ans;}
};