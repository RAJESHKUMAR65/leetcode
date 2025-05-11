class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1){
            return {};
        }

        sort(changed.begin(),changed.end());
        unordered_map<int,int>freq;
        for(auto &nums:changed){
             freq[nums]++;
        }
        vector<int>result;
        for(auto &nums:changed){
            int twice=2*nums;
            if(freq[nums]==0)continue;
            if(freq.find(twice)==freq.end()||freq[twice]==0){
                return {};
            }
            result.push_back(nums);
            freq[nums]--;
            freq[twice]--;
        }
        return result;
    }
};