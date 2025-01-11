class Solution {
public:
   static bool compare(vector<int>&a,vector<int>&b){
     if(a[0]==b[0]){
        return a[1]>b[1];
     }
     return a[0]<b[0];
   }
   int solveUsingRecursion(vector<vector<int>>&envelopes,int curr,int prev){
      if(curr>=envelopes.size()){
        return 0;
      }
       int include=0;
      if(prev==-1 ||(envelopes[curr][0]>envelopes[prev][0]&&envelopes[curr][1]>envelopes[prev][1])){
        include=1+solveUsingRecursion(envelopes,curr+1,curr);
      }
      int exclude=solveUsingRecursion(envelopes,curr+1,prev);
      return max(include,exclude);
   }
   int solveUsingMemo(vector<vector<int>>&envelopes,int curr,int prev ,vector<vector<int>>&dp){
     if(curr>=envelopes.size()){
        return 0;
      }
       int include=0;
       if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
       }
      if(prev==-1 ||(envelopes[curr][0]>envelopes[prev][0]&&envelopes[curr][1]>envelopes[prev][1])){
        include=1+solveUsingMemo(envelopes,curr+1,curr,dp);
      }
      int exclude=solveUsingMemo(envelopes,curr+1,prev,dp);
      return dp[curr][prev+1]=max(include,exclude);
   }
   int binarysearchdp(vector<vector<int>>&envelopes){

      vector<int>ans;
      ans.push_back(envelopes[0][1]);
      for(int i=1;i<envelopes.size();i++){
        if(envelopes[i][1]>ans.back()){
            ans.push_back(envelopes[i][1]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
            ans[index]=envelopes[i][1];
        }
      }
      return ans.size();
   }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        sort(envelopes.begin(),envelopes.end(),compare);
        int curr=0;
        int prev=-1;
       // int ans=solveUsingMemo(envelopes,curr,prev,dp);
       int ans=binarysearchdp(envelopes);
       
        
         return ans;
         
    }
};