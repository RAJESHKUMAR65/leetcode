class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]={0};
        bool ans=true;
        for(int i=0;i<sentence.size();i++){
            arr[sentence[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(arr[i]==0){
                ans=false;
                break;
            }
        }
        return ans;
    }
};