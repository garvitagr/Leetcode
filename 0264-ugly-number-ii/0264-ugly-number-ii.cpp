class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0,j=0,k=0;
        vector<int>ans(1,1);
        while(ans.size()<n){
      int two=ans[i]*2,three=3*ans[j],five=5*ans[k];
      int val=min({two,three,five});
      if(val==two){
         ans.push_back(val);i++;
      }
      else if(val==three){
         ans.push_back(three);j++;
      }
      else if(val==five){
         ans.push_back(five);k++;
      }
      if(ans.size()>1 and ans.back()==ans[ans.size()-2])ans.pop_back();
   }
   return ans.back();
    }
};