/* Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4 */


class LRUCache {
    size_t m_capacity;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int,int>>::iterator> m_map;
public:
    LRUCache(int capacity) : m_capacity(capacity){
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        // does not exist
        if (found_iter == m_map.end())
            return -1;
        // using splice to move the key value pair corresponding to found node to front of the list
        m_list.splice(m_list.begin(), m_list, found_iter->second);
        return m_list.begin()->second; // or found_iter->second->second
    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            m_list.begin()->second = value;
            return;
        }
        // key not found, means we need to insert and check for capacity
        if (m_map.size() == m_capacity)
        {
            int key_to_del = m_list.back().first;
            m_map.erase(key_to_del);  //remove key in map
            m_list.pop_back(); //remove node in list;
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */