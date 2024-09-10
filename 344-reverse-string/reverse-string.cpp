class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            
        }
        
       for(int i=0;i<s.size();i++){
         char ch=st.top();
         s[i]=ch;
         st.pop();
       }
    }
};