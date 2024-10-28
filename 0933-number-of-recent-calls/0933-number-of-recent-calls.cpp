class RecentCounter {
public:
    vector<int> time; 
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(t==NULL){
            return NULL;
        }
        time.push_back(t);
        int counter=0;
        for(auto x:time){
            if(t-x<=3000){
                counter++;
            }
        }
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */