class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=0;
                    fruits[i]=0;
                    break;
                }
            }
        }
        for(auto i:fruits){
            cout<<i<<",";
        }
        cout<<endl;
        for(auto i:baskets){
            cout<<i<<",";
        }
        int ans=0;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i]!=0){
                ans++;
            }
        }
        return ans;
    }
};