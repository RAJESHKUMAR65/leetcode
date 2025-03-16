class Solution {
public:
    int compress(vector<char>& chars) {
         int index=0;
         char curr_char=chars[0];
         int char_count=1;
         for(int i=1;i<chars.size();i++){
             
              if(chars[i]==curr_char){
                 char_count++;
              }
              else{
                chars[index]=curr_char;
                index+=1;
                 if(char_count>1 && char_count<10){
                    chars[index]=char_count+'0';
                    index+=1;
                 }
                 else if(char_count>=10){
                    string temp=to_string(char_count);
                    for(int i=0;i<temp.size();i++){
                        chars[index]=temp[i];
                        index+=1;
                    }
                 }
                curr_char=chars[i];
                char_count=1;
              }
         }
         if(char_count>1&&char_count<9){
          chars[index]=curr_char;
          index+=1;
          chars[index]=char_count+'0';
          index+=1;
         }
          else if(char_count==1){
            chars[index]=curr_char;
            index+=1;
             
        }
        else{
            chars[index]=curr_char;
            index+=1;
             string ans=to_string(char_count);
             for(int i=0;i<ans.length();i++){
                chars[index]=ans[i];
                index+=1;
             }
     
        }
         return index;
    }
};