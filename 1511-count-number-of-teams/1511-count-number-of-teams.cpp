class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int>smaller,larger;
        int n=rating.size(),i,ans=0;
        for(i=0;i<n;i++){
            int val=rating[i],sm=0,lr=0;
            for(int j=i+1;j<n;j++){
                if(val>rating[j])lr++;
                if(val<rating[j])sm++;
            }
            smaller.emplace_back(sm);
            larger.emplace_back(lr);

        }
        for(i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[i]>rating[j])ans+=larger[j];
                if(rating[i]<rating[j])ans+=smaller[j];
            }
        }
        return ans;
    }
};