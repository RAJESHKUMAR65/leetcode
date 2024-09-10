class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                //closing bracket
                if(st.empty()){
                    st.push(s[i]);
                    
                }
                else{
                    char ch=st.top();
                    if(ch=='(' && s[i]==')'){
                        st.pop();
                    }
                    else if(ch=='{' && s[i]=='}'){
                        st.pop();
                    }
                    else if(ch=='[' && s[i]==']'){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
      
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
       
    }
};