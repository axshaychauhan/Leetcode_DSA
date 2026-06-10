class LRUCache {
    private:
        int storage = 0;
        list<pair<int,int>> cache;
        unordered_map<int, std::list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity):storage(capacity) {}
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()){
            cache.splice(cache.begin(), cache,it->second);
            it->second->second = value;
        }
        else{
            if(storage == mp.size()){
                auto it = cache.back();
                mp.erase(it.first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            mp[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */