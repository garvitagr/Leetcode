class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string direction) {
        stack<pair<char,pair<int,int>>>st;  //{dir,{health,pos number}};
        vector<pair<int,pair<int,char>>>v;  //{pos number,{health,dir}};
        for(int i=0;i<positions.size();i++){
            v.push_back({positions[i],{healths[i],direction[i]}});
        }
        sort(v.begin(),v.end());
        unordered_map<int,int>mp;
        int i;
        for(i=0;i<direction.size();i++){
            if(v[i].second.second=='R')st.push({'R',{v[i].second.first,v[i].first}});
            else{
                if(st.empty() or (!st.empty() and st.top().first=='L'))st.push({'L',{v[i].second.first,v[i].first}});
                else{
                    bool add=true;
                    while(!st.empty() and st.top().first=='R'){
                        int robot1health=st.top().second.first;
                        int robot2health=v[i].second.first;
                        if(robot1health<robot2health)v[i].second.first--,st.pop();
                        else if(robot1health>robot2health){
                            auto top=st.top();
                            st.pop();
                            st.push({top.first,{top.second.first-1,top.second.second}});
                            add=false;
                            break;
                        }
                        else{
                            add=false;
                            st.pop();
                            break;
                        }
                    }
                    if(add)st.push({'L',{v[i].second.first,v[i].first}});
                }
            }
        }

        vector<int>result;
        while(!st.empty()){
            mp.insert({st.top().second.second,st.top().second.first});
            st.pop();
        }

        for(i=0;i<positions.size();i++){
            if(mp[positions[i]])result.push_back(mp[positions[i]]);
        }
        return result;
    }
};