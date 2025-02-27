class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.length()>2){
            string k="";
            for(int i=0;i<s.size()-1;i++){
                int sum=(int(s[i])+int(s[i+1]))%10;
                k+=(char)(sum);
            }
            s=k;
            
        }
         return s[0]==s[1];
    }
};