#define pii pair<int,int>

class LRUCache {
public:
    list<pii> q;
    int capacity, size;
    unordered_map<int, list<pii>::iterator> cache;
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size=0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        
        int value = cache[key]->second;
        
        q.erase(cache[key]);      
        q.push_front(pii(key,value));
        cache[key] = q.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            q.erase(cache[key]);      
            q.push_front(pii(key,value));
            cache[key] = q.begin();
            
            return;
        }
        
        if(this->size == this->capacity){
            
            pii rem = q.back(); q.pop_back();            
            cache.erase(rem.first);
            this->size--;
        }
        
        this->size++;
        q.push_front(pii(key,value));
        cache[key]=q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */