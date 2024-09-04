class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obstacles) {
        vector<set<int>>vx(80000),vy(80000);
        for(int i=0;i<obstacles.size();i++){
            int x=obstacles[i][0];
            int y=obstacles[i][1];
            vx[x+40000].insert(y);
            vy[y+40000].insert(x);
        }
        pair<int,int>dir={0,1},pos={0,0};
        int ans=0;

        for(int i=0;i<com.size();i++){
            if(com[i]>0){
                int moves=com[i];
                if(dir.first==1){
                    for(int j=1;j<=moves;j++){
                        int newx=pos.first+1;
                        int newy=pos.second;
                        if(vy[newy+40000].find(newx)!=vy[newy+40000].end())break;
                        else pos={newx,newy};
                        ans=max(ans,pos.first*pos.first + pos.second*pos.second);
                    }
                }
                else if(dir.first==-1){
                    for(int j=1;j<=moves;j++){
                        int newx=pos.first-1;
                        int newy=pos.second;
                        if(vy[newy+40000].find(newx)!=vy[newy+40000].end())break;
                        else pos={newx,newy};
                        ans=max(ans,pos.first*pos.first + pos.second*pos.second);
                    }
                }
                else if(dir.second==1){
                    for(int j=1;j<=moves;j++){
                        int newx=pos.first;
                        int newy=pos.second+1;
                        if(vx[newx+40000].find(newy)!=vx[newx+40000].end())break;
                        else pos={newx,newy};
                        ans=max(ans,pos.first*pos.first + pos.second*pos.second);
                    }
                }
                else if(dir.second==-1){
                    for(int j=1;j<=moves;j++){
                        int newx=pos.first;
                        int newy=pos.second-1;
                        if(vx[newx+40000].find(newy)!=vx[newx+40000].end())break;
                        else pos={newx,newy};
                        ans=max(ans,pos.first*pos.first + pos.second*pos.second);
                    }
                }
            }
            else if(com[i]==-1){
                // right
                if(dir==(make_pair(0,1)))dir=(make_pair(1,0));
                else if(dir==(make_pair(0,-1)))dir=(make_pair(-1,0));
                else if(dir==(make_pair(1,0)))dir=(make_pair(0,-1));
                else if(dir==(make_pair(-1,0)))dir=(make_pair(0,1));
            }
            else if(com[i]==-2){
                // left
                if(dir==(make_pair(0,1)))dir=(make_pair(-1,0));
                else if(dir==(make_pair(0,-1)))dir=(make_pair(1,0));
                else if(dir==(make_pair(1,0)))dir=(make_pair(0,1));
                else if(dir==(make_pair(-1,0)))dir=(make_pair(0,-1));
            }
        }
        return ans;
    }
};