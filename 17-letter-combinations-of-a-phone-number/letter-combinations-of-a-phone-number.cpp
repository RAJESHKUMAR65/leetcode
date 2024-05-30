class Solution {
public:
void solve(vector<string> &mapping,vector<string> &ans,string digits,string output,int index)
{
    if(index>=digits.length())
    {
        ans.push_back(output);
        return;
    }
    // char dega na toh usko int mai convert krne kei liye '0'
    int value=digits[index]-'0';
    string map=mapping[value];
    for(int i=0;i<map.size();i++)
    {
        output.push_back(map[i]);
        solve(mapping,ans,digits,output,index+1);
        // backtrack
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        vector<string> mapping(10);
        string output="";
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        int index=0;
     solve(mapping,ans,digits,output,index);
     return ans;
    }
};