class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int addup=numbers[i]+numbers[j];
            if(addup==target){
                return {i+1,j+1};
            }
           else if(addup>target){
                 j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};