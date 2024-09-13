class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        // jadu hein
        st.push(-1);
        int count =0;
       for(int i=0;i<s.length();i++){
           char ch=s[i];
           if(ch=='('){
            st.push(i);
           }
           else{
            // closing wale case mein phele pop krunga 
            // pop kr raha hu agar stack empty huwa toh
            // initially mein -1 insert kr raha hu woh wala case nhi bnega empty wala smje
            //-1 kyu insert kr raha hu kyuki muje length nikalne hei leftmost minus rightmost
            // krunga toh length aa jyege but why -1 hr case mein -1 hoga kya leftmost
            // agar valid parenthesis chal rahe toh thik agar break kr gye toh
            // us bracket ka index  insert krunga jisko mein reject kr raha 
            //valid parenthesis kei count mein
            // kyuki wahi leftmost hoga na bhaii
            // socho beth kr
             st.pop();
               if(st.empty()){
                            // st.empty hein
                     // phele thought kei stack mein -1 dal du
                     // pr answer galat ayega
                     // toh kya krna chaye agar mera closing bracket aur mera stack empty
                     // toh bracket answer nhi bneyega na toh mera valid paraentheis
                     // wala wahi sey suru hoga
                     // isliye mein usko leftmost element manunga 
                     st.push(i);
               }
               else{
             
                       // woh index jisme mein kada hu rigthmost hei means i
                // leftmost mera stack ka top 
                   int length=i-st.top();
                   count=max(length,count);
               }
           }
       }
       
        return count; 
    }
};