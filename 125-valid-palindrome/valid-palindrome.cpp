class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
            }
           else if(s[i]>='a' && s[i]<='z')
           {
              continue;
           }
           else if(isdigit(s[i]))
           {
            continue;
           }
           
           else
           {
            s.erase(i,1);
            i--;
            len--;
           }
            
        }
        
         
      
         
         int i=0;
         int j=len-1;
         while(i<=j)
         {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
         }
         return true;
    }
};