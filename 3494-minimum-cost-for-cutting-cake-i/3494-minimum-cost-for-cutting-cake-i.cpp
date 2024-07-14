class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        int i=0,j=0,ans=0;
        int rowmul=1,colmul=1;
        m--;n--;
        sort(hor.rbegin(),hor.rend());
        sort(ver.rbegin(),ver.rend());
        while(i<m and j<n){
            if(hor[i] < ver[j]){
                ans+=ver[j++]*colmul;
                rowmul++;
            }
            else{
                ans+=hor[i++]*rowmul;
                colmul++;
            }
        }
        while(i<m){
            ans+=hor[i++]*rowmul;
        }
        while(j<n){
            ans+=ver[j++]*colmul;
        }
        return ans;
    }
};