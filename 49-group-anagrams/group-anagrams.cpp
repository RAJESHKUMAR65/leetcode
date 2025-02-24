class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>sorting_info;
        vector<vector<string>>result;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            sorting_info[str].push_back(strs[i]);}
        for(auto it:sorting_info){
         
            result.push_back(it.second);
           
        }
       return result;
    }
};