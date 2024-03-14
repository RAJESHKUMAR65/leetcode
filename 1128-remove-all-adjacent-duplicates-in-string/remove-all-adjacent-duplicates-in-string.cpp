class Solution {
public:
    string removeDuplicates(string s) {
        string temp="";
        int i=0;
        
        
        while(i<s.length())
         {
            if(temp.empty())
            {
                temp.push_back(s[i]);
                i++;
            }
            else
            {
                if(temp.back()!=s[i])
                {
                    temp.push_back(s[i]);
                    i++;
                }
                else
                {
                    temp.pop_back();
                    i++;
                }
            }
         }
             
        
        return temp;

    }
        
};