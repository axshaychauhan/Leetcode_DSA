class LRUCache {
public:
    LRUCache(int capacity) {
        storage = capacity;
    }
    
    int get(int key) {
        auto it = mpKeyNode.find(key);
        if(it == mpKeyNode.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return  it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mpKeyNode.find(key);
        if(it != mpKeyNode.end()){
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second); 
        }
        else {
            if(storage == mpKeyNode.size()) {
                auto itBack = cache.back();
                mpKeyNode.erase(itBack.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            mpKeyNode[key] = cache.begin();
        }
        
    }

    private:
    int storage;
    std::list<pair<int, int>> cache;

    unordered_map<int, std::list<pair<int,int>>::iterator> mpKeyNode;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */