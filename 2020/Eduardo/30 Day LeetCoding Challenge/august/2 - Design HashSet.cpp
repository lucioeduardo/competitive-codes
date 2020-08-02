#define MAXN 1000100

class MyHashSet {
public:
    bool exist[MAXN];
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(exist,false,sizeof(exist));
    }
    
    void add(int key) {
        exist[key]=true;
    }
    
    void remove(int key) {
        exist[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return exist[key];
    }
};
