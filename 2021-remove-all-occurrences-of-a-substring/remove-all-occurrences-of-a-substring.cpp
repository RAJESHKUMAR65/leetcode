class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len=part.length();
       int i=s.find(part);
        while(i!=string::npos)
        {
        

            s.erase(i,len);
            i=s.find(part);
        }
        return s;
        
    }
};