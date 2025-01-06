class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{'||ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    int topelement=st.top();
                    if(ch==')'&& topelement=='('){
                        st.pop();
                    }
                   else if(ch=='}'&& topelement=='{'){
                       st.pop();}
                    else if(ch==']' && topelement=='['){
                        st.pop();
                    }
                    else{
                        return false;
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