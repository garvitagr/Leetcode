class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        unordered_map<string,int>visited,mp;
        for(int i=0;i<deadends.size();i++)mp[deadends[i]]++;
        if(mp["0000"])return -1;
        int ans=INT_MAX;
        visited["0000"]=1;
        q.push({"0000",0});
        while(!q.empty()){
            string s=q.front().first;
            int cost=q.front().second;
            q.pop();
            if(s==target){
                ans=min(ans,cost);
                continue;
            }
            
            for(int i=0;i<4;i++){
                // add
                string add=s,sub=s;
                if(add[i]=='9'){
                    add[i]='0';
                    if(!visited[add] and !mp[add]){
                        q.push({add,cost+1});
                        visited[add]++;
                    }
                    
                }
                else{
                    add[i]++;
                    if(!visited[add] and !mp[add]){
                        q.push({add,cost+1});
                        visited[add]++;
                    }
                }

                // sub
                if(sub[i]=='0'){
                    sub[i]='9';
                    if(!visited[sub] and !mp[sub]){
                        q.push({sub,cost+1});
                        visited[sub]++;
                    }
                }
                else{
                    sub[i]--;
                    if(!visited[sub] and !mp[sub]){
                        q.push({sub,cost+1});
                        visited[sub]++;
                    }
                }
            }
        }

        return (ans==INT_MAX?-1:ans);

    }
};