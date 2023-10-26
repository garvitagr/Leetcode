class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int>maxileft,minileft;
        int i,x=nums[0],ind=0,y;
        for(i=0;i<nums.size();i++){
            if(x<=nums[i]){
                minileft.push_back(ind);
            }
            else{
                x=nums[i];
                ind=i;
                minileft.push_back(ind);
            }
        }
        for(i=nums.size()-1;i>=0;i--){
            if(i-indexDifference<0)break;
            x=nums[i];
            y=minileft[i-indexDifference];
            if(abs(x-nums[y])>=valueDifference){
                return{y,i};
            }
        }
        x=nums[0];ind=0;

        for(i=0;i<nums.size();i++){
            if(x>=nums[i]){
                maxileft.push_back(ind);
            }
            else{
                x=nums[i];
                ind=i;
                maxileft.push_back(ind);
            }
        }

        for(i=nums.size()-1;i>=0;i--){
            if(i-indexDifference<0)break;
            x=nums[i];
            y=maxileft[i-indexDifference];
            if(abs(x-nums[y])>=valueDifference){
                return{y,i};
            }
        }
        return {-1,-1};
    }
};