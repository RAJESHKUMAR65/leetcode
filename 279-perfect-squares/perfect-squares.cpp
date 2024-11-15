class Solution {
public:
    vector<int> perfectSquare(int n){
    vector<int> perfect_array;
      for(int i=1;i<=n;i++){
            int j=sqrt(i);
            if(j*j==i){
               perfect_array.push_back(i);
            }
      }
      return perfect_array;
    }
    int solveUsingRecursion(vector<int>&arr,int n,vector<int>&dp){
          if(n==0){
            return 0;
          }
          if(n<0){
            return INT_MAX;
          }
         if(dp[n]!=-1){
            return dp[n];

         }
         
          int final=INT_MAX;
          for(int i=0;i<arr.size();i++){
            int ans=solveUsingRecursion(arr,n-arr[i],dp);
            if(ans!=INT_MAX){
                 final=min(final,ans+1);
            }
          }
          dp[n]=final;
          return dp[n];
    }

    int solveUsingtab(vector<int>&arr,int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
                   int final=INT_MAX;
          for(int j=0;j<arr.size();j++){
            int ans=solveUsingRecursion(arr,i-arr[j],dp);
            if(ans!=INT_MAX){
                 final=min(final,ans+1);
            }
          }
          dp[i]=final;
        }
      return dp[n];
    }
   
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        vector<int> arr=perfectSquare(n);
        int ans=solveUsingtab(arr,n);
        return ans;
       
    }
};