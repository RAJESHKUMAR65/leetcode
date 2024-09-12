class MinStack {
public:
// vector bnaya hei pair ka  phele value normal value of stack dekha raha hei
/// dursra value aabtak ka minimum dekha raha hei
   vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int>p=make_pair(val,val);
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            p.second=min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
       st.pop_back(); 
    }
    
    int top() {
        if(st.empty()){
             return -1;
        }else{
           return st.back().first;
        }
       
    }
    
    int getMin() {
        if(st.empty()){
             return -1;
        }else{
            return st.back().second;
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */