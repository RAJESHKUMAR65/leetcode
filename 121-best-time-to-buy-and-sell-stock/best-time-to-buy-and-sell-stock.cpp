class Solution {
public:
   void solveUsingRecursion(vector<int>&prices,int i,int &minPrice,int &MaxProfit){
      if(i>=prices.size()) return;
      if(prices[i]<minPrice) minPrice=prices[i];
      int todayprofit=prices[i]-minPrice;
      if(todayprofit>MaxProfit) MaxProfit=todayprofit;
      solveUsingRecursion(prices,i+1,minPrice,MaxProfit);
   }
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        solveUsingRecursion(prices,0,minPrice,maxProfit);
        return maxProfit;
    }
};