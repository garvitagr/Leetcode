class MyCalendar {
public:
    set<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.empty()){
            v.insert(make_pair(start,end));
            return true;
        }
        auto it=v.upper_bound({end,start});
        it--;
        pair<int,int>pr=*it;
        int oldstart=pr.first;
        int oldend=pr.second;
        cout<<oldstart<<" "<<oldend<<endl;
        if(oldend<=start or end<=oldstart){
            v.insert(make_pair(start,end));
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */