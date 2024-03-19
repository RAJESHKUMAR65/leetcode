class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int mx = 0;
        for (auto it : tasks)
       {
        mp[it]++;
        if (mp[it] > mx)
        mx = mp[it];
       }
       int ct = 0;
    for (auto it : mp)
    {
    if (it.second == mx)
    ct++;
    }
    int size = tasks.size();
    return max(((n + 1) * (mx - 1) + ct), size);
    }
};