class Solution {
public:
    vector<int>minOperations(string boxes) {
        vector<int>ans(boxes.size());
        for(int i=0;i<boxes.size();i++){
            int val=0;
            for(int j=0;j<boxes.size();j++){
                if(i!=j and boxes[j]=='1')val+=abs(i-j);
            }
            ans[i]=val;
        }
        return ans;
    }
};