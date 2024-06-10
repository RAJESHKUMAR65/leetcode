class Solution {
public:
string add(string num1,string num2,int i,int j,int carry=0)
{
    // base case
    if(i<0 && j<0)
    {
        if(carry!=0)
        {
            return string(1,carry+'0');
        }
        else{
            return "";
        }

    }
    int n1=(i>=0?num1[i]:'0')-'0';
    int n2=(j>=0?num2[j]:'0')-'0';
    int csum=n1+n2+carry;
    int digit=csum%10;
     carry=csum/10;
    string ans="";
    ans.push_back(digit+'0');
    ans+= add(num1,num2,--i,--j,carry);
    return ans;

}
    string addStrings(string num1, string num2) {
         int i=num1.length()-1;
         int j=num2.length()-1;
       string ans= add(num1,num2,i,j);
       reverse(ans.begin(),ans.end());
       return ans;
    }
};