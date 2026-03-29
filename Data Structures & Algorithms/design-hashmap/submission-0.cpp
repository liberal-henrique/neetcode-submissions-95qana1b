#include <unordered_map>

class MyHashMap {
public:
    unordered_map<int, int> um;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            um[key] = value;
        } else {
            um.insert({key, value});
        }
    }
    
    int get(int key) {
        if (um.find(key) != um.end())
            return um[key];
        return -1;
    }
    
    void remove(int key) {
        if (um.find(key) != um.end())
            um.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */