class node{
    public:
    char data;
    int count;
    node(char d,int c){
        data =d;
        count=c;
    }

};
class compare{
    public:
    bool operator()(node a,node b){
        return a.count<b.count;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        //phele ek array bnaya freq count kei liye
        // initially sabke kei count zero 
        // haar character kei frequency ka map bna kr count rakha
        int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
           char ch=s[i];
           freq[ch-'a']++;
        }
        //maxheap create krna jisme mai char aur uske frequecy ko store krunga
        priority_queue<node,vector<node>,compare>maxHeap;
        for(int i=0;i<26;i++){
            //sare charcter aur uske freq ka node maxHeap mai daal diya
            if(freq[i]!=0)
            {
              node temp(i+'a',freq[i]);
              maxHeap.push(temp);

            }
        }
        string ans="";
        while(maxHeap.size()>1){
            node first=maxHeap.top();
            maxHeap.pop();
            node second=maxHeap.top();
            maxHeap.pop();
            ans+=first.data;
            ans+=second.data;
            first.count--;
            second.count--;
            if(first.count!=0){
                maxHeap.push(first);
            }
            if(second.count!=0){
                maxHeap.push(second);
            }

        }
        if(maxHeap.size()==1){
            node temp=maxHeap.top();
            if(temp.count==1){
                ans+=temp.data;

            }
            else{
                return "";
            }
        }
        return ans;


    }
};