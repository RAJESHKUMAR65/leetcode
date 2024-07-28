class Solution {
public:
    int rec(vector<int>& nums, int i) {
      //base case
      if(i>=nums.size()){
        return 0;
      }
      
      // ek baar include kiya 
       int robamnt1=nums[i]+rec(nums,i+2);
       //dusre baar nhi kiya include exclude
       int robamnt2=0+rec(nums,i+1);

       return max(robamnt1,robamnt2);
    
  

    }

    //  solve using recursion n is ending index
   int solveUsingRecursion(vector<int>&nums,int n){
    //koi ghar nhi hei robbing kei liye
    if(n<0){
        return 0;
    }
    // ek hei ghar hu 
    if(n==0){
        return nums[0];
    }

    int include=solveUsingRecursion(nums,n-2)+nums[n];
    int exclude=solveUsingRecursion(nums,n-1)+0;

    return max(include,exclude);
   }

   int solveUsingMemo(vector<int>&nums,int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    // ek hei ghar hu 
    if(n==0){
        return nums[0];
    }
    //step3:check kro dp array mai phelesey hei kya
    if(dp[n]!=-1){
        return dp[n]; //n house tak aate tum kitma money kaama chuke ho
    }

    int include=solveUsingMemo(nums,n-2,dp)+nums[n];
    int exclude=solveUsingMemo(nums,n-1,dp)+0;
    // jaha answer store ho raha hei usko dp[] array mai kro
    dp[n]= max(include,exclude);
    return dp[n];
   }

   //bottom up appraoch
   int solveUsingTab(vector<int>&nums,int n){
    vector<int>dp(n+1,0);// yaha maximum amount chaye tum int_min bhi use
    // kr skte ho pr int_min wala case alagsey solve krna padega
    // question padenge toh zero bhi rakh skte hei

    //step2:base case dekho
    dp[0]=nums[0];//ek ghar hoga toh
    
    //step3:0 sey n chalega
    for(int i=1;i<=n;i++){
        int temp=0;
         if(i-2>=0){
            temp=dp[i-2];
         }
           int include=temp+nums[i];
           int exclude=dp[i-1]+0;
    // jaha answer store ho raha hei usko dp[] array mai kro
          dp[i]= max(include,exclude);
          
    }
    return dp[n];

    
    
   }

   int solveUsingSpaceOptimisation(vector<int> &nums,int n){
     //vector<int>dp(n+1,0);// yaha maximum amount chaye tum int_min bhi use
    // kr skte ho pr int_min wala case alagsey solve krna padega
    // question padenge toh zero bhi rakh skte hei

    int prev2=0;
    int prev1=nums[0];
    int curr=0;

    
    //step3:0 sey n chalega
    for(int i=1;i<=n;i++){
        int temp=0;
         if(i-2>=0){
            temp=prev2;
         }
           int include=temp+nums[i];
           int exclude=prev1+0;
    // jaha answer store ho raha hei usko dp[] array mai kro
          curr= max(include,exclude);
          prev2=prev1;
          prev1=curr;
          
    }
    return prev1;// prev1

   }
    int rob(vector<int>& nums) {
        
    //   return rec(nums,0);
    int n=nums.size()-1;

    // return solveUsingRecursion(nums,nums.size()-1);
    // vector<int> dp()

     //step1:dp array create krna
     //code dekho change n ho raha hei
    //  vector<int>dp(n+1,-1);
    //  return solveUsingMemo(nums,n,dp);

    // return solveUsingTab(nums,n);

    return solveUsingSpaceOptimisation(nums,n);


        
        
    }
};