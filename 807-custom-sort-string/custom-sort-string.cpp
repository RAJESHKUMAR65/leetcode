class Solution {
public:
    string customSortString(string order, string s) {
      int arr[26] ={0};
      int count=0;
      for(int i=0;i<s.length();i++)
      {
          int temp=s[i]-'a';
          arr[temp]++;
      }
      while(!s.empty())
      {
          s.pop_back();
      }
      for(int i=0;i<order.length();i++)
      {
          int temp=order[i]-'a';
          while(arr[temp]!=0)
          {
              s.push_back(order[i]);
              arr[temp]--;
              
          }
      }
      for(int i=0;i<26;i++)
      {
          if(arr[i]!=0)
          {
              char ch=i+'a';
              while(arr[i]!=0)
              {
                  s.push_back(ch);
                  arr[i]--;
              }
              
          }
      }
      return s;

    }
};