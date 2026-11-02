class LRUCache {
public:

    int size = 0;

    list<pair<int, int>> dq;

    unordered_map<int, list<pair<int,int>> :: iterator> map;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {


        if(map.find(key) == map.end()){
            return -1;
        }

        int value = map[key]->second;
        // map.erase(key);
        put(key,value);

        return value;
        
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end()){
            dq.erase(map[key]);
            map.erase(key);
        }else if(dq.size() == size){
            auto f = dq.front().first;
            dq.pop_front();
            map.erase(f);
        }

        dq.push_back({key,value});
        map[key] = --dq.end();
        // map[key] = {key,value};

        
    }
};
