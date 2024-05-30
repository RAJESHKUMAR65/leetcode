class Solution {
public:
 void  solve(vector<string> &ans,int open ,int close,string output)
   {
    // base case
    // jab tumra opening and closing bracket khatm hogye ho
    if(close==0 && open == 0)
    {
        ans.push_back(output);
        return;
    }

    // open bracket ko include krna 
// open bracket ko jab include kr skta hu jab mera opening bracket ka count ho
  if(open>0)
  {
    output.push_back('(');
    solve(ans,open-1,close,output);
    // backtrack kr raha hu
    output.pop_back();
  }

  // close bracket jab hei include kr skta jab mere pass 
 // opening bracket ho
 // so mere pass opening ka count kam hona chaye closing sey kyuki mai opening
// phele sey use kr chuka
  if(close>open)
  {
    output.push_back(')');
    solve(ans,open,close-1,output);
    // backtrack 

    output.pop_back();
  }

    // closing bracket ko include krna 
   }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string output="";
        solve(ans,open ,close,output);
        return ans;
    }
};