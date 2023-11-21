class LRUCache {
public:
    LRUCache(int capacity) {
        NUM = capacity;
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if (iter == cache.end())    //没找到
            return -1;
        int result = (iter->second).first;
        //更新缓存访问时间,变成最新
        if (key_in_LRU.front() != key)
        {
            key_in_LRU.erase((iter->second).second);
            (iter->second).second = key_in_LRU.insert(key_in_LRU.begin(), key);
        }
        return result;
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        if (iter == cache.end())     //不存在
        {
            //插入
            //判断是否超出容量
            if (key_in_LRU.size() == NUM)     //超出最大容量
            {
                //删除缓存
                int key_in_last = key_in_LRU.back();    //获取cache对应的key
                key_in_LRU.pop_back();
                cache.erase(key_in_last);
                //插入新节点
                auto iter1 = key_in_LRU.insert(key_in_LRU.begin(), key);
                cache.insert({key, {value, iter1}});
            }
            else
            {
                //插入新缓存
                auto iter1 = key_in_LRU.insert(key_in_LRU.begin(), key);
                cache.insert({key, {value, iter1}});
            }
        }
        else     //存在这个key
        {
            //更新value
            // auto iter = cache.find(key);
            (iter->second).first = value;
            //更新链表中结点顺序
            if (key_in_LRU.front() != key)
            {
                key_in_LRU.erase((iter->second).second);
                (iter->second).second = key_in_LRU.insert(key_in_LRU.begin(), key);
            }
        }
    }
private:
    int NUM;
    list<int> key_in_LRU;   //记录每个缓存使用时间
    unordered_map<int, pair<int,list<int>::iterator>> cache; //缓存主体
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */