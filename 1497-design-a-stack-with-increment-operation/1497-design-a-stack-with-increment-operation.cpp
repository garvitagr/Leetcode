class CustomStack {
public:
    vector<int>v;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(v.size()<size)v.push_back(x);
    }
    
    int pop() {
        int val;
        if(!v.empty()){
            val=v.back();
            v.pop_back();
            return val;
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        int sz=v.size();
        for(int i=0;i<min(sz,k);i++)v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */