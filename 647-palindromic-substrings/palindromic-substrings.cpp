class Solution {
public:
int expand(string s,int i,int j)
{
    int count=0;
    while(i>=0 && j<s.length() && s[i]==s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}
  
 
    int countSubstrings(string s) {
        int totalcount=0;
        for(int centre=0;centre<s.length();centre++)
        {
            // odd substring alag handle
            int oddkaAns=expand(s,centre,centre);
            // even substring alag handle 
            int evenkaAns=expand(s,centre,centre+1);
            totalcount +=oddkaAns+evenkaAns;
        }
        
        return totalcount;

    }
};