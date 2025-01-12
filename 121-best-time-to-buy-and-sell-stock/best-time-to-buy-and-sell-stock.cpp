class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>rightGreater(n,-1);
        rightGreater[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            rightGreater[i]=max(rightGreater[i+1],prices[i]);
        }
        int profit=INT_MIN;
      for(int i=0;i<n;i++){
          if(prices[i]<rightGreater[i]){
            profit=max(profit,rightGreater[i]-prices[i]);
          }
      }
      if(profit!=INT_MIN) return profit;
      return 0;
     
    }
};