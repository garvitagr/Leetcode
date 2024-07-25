class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]*-1);
        for(int i=0;i<nums.size();i++){
            int val=pq.top()*-1;
            nums[i]=val;
            pq.pop();
        }
        return nums;
    }
};