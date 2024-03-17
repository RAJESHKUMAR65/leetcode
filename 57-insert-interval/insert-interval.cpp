class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size();i++){
            vector<int> temp = intervals[i];
            while(i < intervals.size() && temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]);
                i++;
            }
            if(i < intervals.size() && temp != intervals[i]) i--;
            ans.push_back(temp);
        }
        return ans;
    }
};