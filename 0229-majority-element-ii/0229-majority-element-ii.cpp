class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // By using boyer's moore majority voting algorithm
        
        int ele1=-1,ele2=-1,ct1=0,ct2=0,ct=0,i,n=nums.size();
        vector<int>ans;
        
        for(auto ele:nums){
            if(ele==ele1)ct1++;
            else if(ele==ele2)ct2++;
            else if(ct1==0){
                ele1=ele;
                ct1++;
            }
            else if(ct2==0){
                ele2=ele;
                ct2++;
            }
            else{
                ct1--;ct2--;
            }
        }
        ct1=0;ct2=0;
        for(auto ele:nums){
            if(ele==ele1)ct1++;
            else if(ele==ele2)ct2++;
        }
        if(ct1>n/3)ans.push_back(ele1);
        if(ct2>n/3)ans.push_back(ele2);

        return ans;
    }
};