class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         vector<vector<int>>ans;
          vector<int> result;
        for(int i=0;i<arr.size();i++){
            vector<int>temp;
            int a=abs(arr[i]-x);
            temp.push_back(a);
            temp.push_back(arr[i]);
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
         
        for(int i=0;i<ans.size();i++){
            if(k!=0){
                result.push_back(ans[i][1]);
            }
            else{
                break;
            }
            k--;
        }
         sort(result.begin(),result.end());
         return result;
    }
};