class Solution {
public:
   bool checkPalindrome(int i,int j,string &s){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
   }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                  if(checkPalindrome(i,j,s)) count++;
            }
        }
        return count;
    }
     
};