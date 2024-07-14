class Solution {
public:
    int dist(int x,int y,vector<vector<int>>& points){
        return abs(points[x][0]-points[y][0]) + abs(points[x][1]-points[y][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int,int>>st;
        st.insert({0,0});
        int ans=0,i,n=points.size();
        vector<int>visited(n,0);
        while(!st.empty()){
            auto pr=st.begin();
            int curnode=pr->second;
            int dis=pr->first;
            st.erase(pr);
            if(visited[curnode])continue;
            visited[curnode]=1;
            ans+=dis;
            for(i=0;i<n;i++){
                if(!visited[i])st.insert({dist(i,curnode,points),i});
            }
        }
        return ans;
    }
};