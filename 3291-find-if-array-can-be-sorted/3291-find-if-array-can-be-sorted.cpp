class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int>bits(nums.size()),arr;
        arr=nums;
        sort(arr.begin(),arr.end());
        if(arr==nums)return true;
        int i,st=0,ele=nums[i],f=1;
        for(i=0;i<nums.size();i++){
            bits[i]=__builtin_popcount(nums[i]);
            // cout<<bits[i]<<endl;
        }
        for(i=1;i<nums.size();i++){
            if(bits[i]==bits[i-1])f++;
            else{
                sort(nums.begin()+st,nums.begin()+f);
                st=i;
                f=i+1;
            }
        }
        // cout<<st<<endl<<f<<endl;
        sort(nums.begin()+st,nums.begin()+f);
        // for(i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        return is_sorted(nums.begin(),nums.end());
    }
};