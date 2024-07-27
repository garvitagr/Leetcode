class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long i,n=original.size(),ans=0;
        vector<vector<long long>>dis(26,vector<long long>(26,LLONG_MAX));
        for(i=0;i<original.size();i++){
            char u=original[i];
            char v=changed[i];
            long long w=cost[i];
            dis[u-'a'][v-'a']=min(dis[u-'a'][v-'a'],w);
        }
        for(int u=0;u<26;u++)dis[u][u]=0;

        for(int via=0;via<26;via++){
            for(int u=0;u<26;u++){
                for(int v=0;v<26;v++){
                    if(dis[u][via]==LLONG_MAX)continue;
                    if(dis[via][v]==LLONG_MAX)continue;
                    dis[u][v]=min(dis[u][via]+dis[via][v],dis[u][v]);
                }
            }
        }
        for(i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dis[u][v]==LLONG_MAX)return -1;
            ans+=dis[u][v];
        }
        return (ans>=LLONG_MAX?-1:ans);
    }
};