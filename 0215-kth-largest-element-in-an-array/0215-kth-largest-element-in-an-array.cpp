class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i;
        priority_queue<int>pq;
        for(i=0;i<k;i++){
            pq.push(nums[i]*-1);
        }
        for(i=k;i<nums.size();i++){
            int topele=pq.top()*-1;
            if(topele<nums[i]){
                pq.pop();
                pq.push(nums[i]*-1);
            }
        }
        return pq.top()*-1;
    }
};