class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int i,n=profits.size(),j=0;
        vector<pair<int,int>>v(n);
        for(i=0;i<n;i++)v[i]={capital[i],profits[i]};
        sort(v.begin(),v.end());

        priority_queue<int>pq;

        for(i=0;i<k;i++){
            while(j<n and w>=v[j].first){
                pq.push(v[j++].second);
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            } 
        }
        return w;
    }
};