class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int>maxHeap;
      // phele sare element max heap mai dalo
      // 
      for(int i=0;i<piles.size();i++){
        maxHeap.push(piles[i]);
      }
      while(k!=0){
        int element=maxHeap.top();
        maxHeap.pop();
        element=element-floor(element/2);
        maxHeap.push(element);
        k--;
      }
      int sum=0;
      while(!maxHeap.empty()){
        sum=sum+maxHeap.top();
        maxHeap.pop();
      }
      return sum;
    }
};