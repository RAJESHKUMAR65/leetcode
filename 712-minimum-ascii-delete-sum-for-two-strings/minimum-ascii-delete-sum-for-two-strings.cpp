class Solution {
public:
    int solveUsingRecursion(string&s1,string&s2,int i,int j){
         int ans=0;
        if(i==s1.size()){
            for(int x=j;j<s2.size();j++){
                ans+=s2[j];
            };
            return ans;
        }
        if(j==s2.size()){
            for(int x=i;i<s1.size();i++){
                ans+=s1[i];
            }
            return ans;
        }
        
        if(s1[i]==s2[j]){
            ans=0+solveUsingRecursion(s1,s2,i+1,j+1);
        }
        else{
            int ans1=s1[i]+solveUsingRecursion(s1,s2,i+1,j);
            int ans2=s2[j]+solveUsingRecursion(s1,s2,i,j+1);
            ans=min(ans1,ans2);
        }
        return ans;

    }

    int solveUsingMemo(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        int ans=0;
        if(i==s1.size()){
            for(int x=j;j<s2.size();j++){
                ans+=s2[j];
            };
            return ans;
        }
        if(j==s2.size()){
            for(int x=i;i<s1.size();i++){
                ans+=s1[i];
            }
            return ans;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            ans=0+solveUsingMemo(s1,s2,i+1,j+1,dp);
        }
        else{
            int ans1=s1[i]+solveUsingMemo(s1,s2,i+1,j,dp);
            int ans2=s2[j]+solveUsingMemo(s1,s2,i,j+1,dp);
            ans=min(ans1,ans2);
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        int ans=solveUsingMemo(s1,s2,0,0,dp);
        return ans;
    }
};