class TimeMap {
public:

    unordered_map<string, vector<pair<string, int>>> map;

    TimeMap() {

        
    }
    
    void set(string key, string value, int t) {
        map[key].push_back({value, t});
    }
    
    string get(string key, int t) {
        
        string res = "";

        if(map.find(key) == map.end()) return "";

        vector<pair<string, int>> &val = map[key];

        int l = 0, r = val.size() - 1;

        while(l <= r){
            int mid = (l+r)/2;

            if(val[mid].second <= t){
                res = val[mid].first;
                l = mid+1;
            }else{
                r = mid-1;
            }

        }

        return res ;

    }
};
