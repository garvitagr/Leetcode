class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tot=0,i,partsum,ct=0;
        for(i=0;i<arr.size();i++)tot+=arr[i];
        if(tot%3!=0)return false;
        partsum=tot/3;tot=0;
        for(i=0;i<arr.size();i++){
            tot+=arr[i];
            if(tot==partsum)ct++,tot=0;
        }
        if(ct>=3)return true;
        return false;
    }
};