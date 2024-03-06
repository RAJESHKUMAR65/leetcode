class Solution {
public:
   int expand_around_index(string s,int i,int j)
   { int count=0;
       while(i>=0 && j<s.length() && s[i]==s[j])
       {
           count++;
           i--;
           j++;
       }
       return count;
   }
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            //odd kei alag handle kiya
            int oddcount=expand_around_index(s,i,i);
            count=oddcount+count;
            //even ka case alag handle kiya
            int evencount=expand_around_index(s,i,i+1);
            count=evencount + count;
        }
        return count;
    }
     
};