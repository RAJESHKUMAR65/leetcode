class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
             int i=s.find(part);
             s.erase(i,part.length());
        }
        return s;
    }
};