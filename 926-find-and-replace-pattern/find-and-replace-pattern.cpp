class Solution {
public:
  void createmapping(string &str)
  {
    char start='a';
    char mapping[300]={0};
    // mapping create kr de
    for(auto ch:str)
    {
        if(mapping[ch]==0)
        {
            mapping[ch]=start;
            start++;
        }
    }
    for(int i=0;i<str.length();++i)
    {
        char temp=str[i];
        str[i]=mapping[temp];
    }
     

  }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // patter ko normalize krna hei
        vector<string> ans;
        createmapping(pattern);
        for(auto str:words)
        {
            string temp=str;
            createmapping(temp);
            if(temp==pattern)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};