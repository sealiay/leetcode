class LRUCache{
public:
    list<int> lt;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> kl;
    int cp;
    LRUCache(int capacity): cp(capacity) {}
    
    int get(int key) {
        auto f = kv.find(key);
        if ( f == kv.end() ) return -1;
        up(key);
        return f->second;
    }
    
    void up(int k) {
        auto f = kl.find(k);
        lt.erase(f->second);
        lt.push_front(k);
        f->second = lt.begin();
    }
    
    void set(int key, int value) {
        auto f = kv.find(key);
        if ( f == kv.end() ) {
            if ( kv.size() == cp ) {
                int k = lt.back();
                lt.pop_back();
                kv.erase(k);
                kl.erase(k);
            }
            lt.push_front(key);
            kv.insert({key, value});
            kl.insert({key, lt.begin()});
        } else {
            f->second = value;
            up(key);
        }
    }
};
