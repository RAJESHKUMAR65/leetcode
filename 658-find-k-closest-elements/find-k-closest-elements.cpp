class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int low=0;
      int high=arr.size()-1;
      vector<int> ans;
      while(high-low>=k){
        if(abs(arr[low]-x)>abs(arr[high]-x)){
            low++;
        }
        else{
            high--;
        }
      }
      for(int i=low;i<=high;i++){
        ans.push_back(arr[i]);
      }
     return ans;

    }
};