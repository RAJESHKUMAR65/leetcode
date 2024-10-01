class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.length()<k){
               string ans="";
               for(int i=0;i<word.length();i++){
                    char ch=  char((word[i]+1)%122);
                    cout<<ch;
                    ans+=ch;
               }
               word+=ans;
        }

     return word[k-1];
    }
};