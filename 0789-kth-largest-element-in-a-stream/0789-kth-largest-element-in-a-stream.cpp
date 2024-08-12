class KthLargest {
public:
    priority_queue<int>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int size=nums.size();
        for(int i=0;i<min(k,size);i++)pq.push(nums[i]*-1);
        for(int i=k;i<nums.size();i++){
            if(pq.top()*-1<nums[i]){
                pq.pop();
                pq.push(nums[i]*-1);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()!=K)pq.push(val*-1);
        else{
            int top=pq.top()*-1;
            if(val>top){
                pq.pop();
                pq.push(val*-1);
            }
        }
        return pq.top()*-1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */