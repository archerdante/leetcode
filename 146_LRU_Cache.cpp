#include <unordered_map>
#include <list>
using namespace std;
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
class LRUCache{
public:
    LRUCache(int capacity) {
        N = capacity;
    }
    
    int get(int key) {
        Map::iterator it = myMap.find(key);
        if(it != myMap.end()) 
        {
            touch(it);
            return it->second.first;
        }
        else return -1;
    }
    
    void set(int key, int value) {
        Map::iterator it = myMap.find(key);
        if(it != myMap.end())
        {
            it->second.first = value;
            touch(it);
        }
        else
        {
            if(myMap.size() == N)
            {
                int delElement = myList.back();
                myList.pop_back();
                myList.push_front(key);
                myMap.erase(delElement);
                myMap[key] = make_pair(value, myList.begin());
            }
            else
            {
                myList.push_front(key);
                myMap[key] = make_pair(value, myList.begin());
            }
        }
    }
private:
    using Li = list<int>;
    using Item = pair<int, Li::iterator>;
    using Map = unordered_map<int, Item>;
    Li myList;
    Map myMap;
    int N = 0;
    void touch(Map::iterator it)
    {
        myList.erase(it->second.second);
        myList.push_front(it->first);
        it->second.second = myList.begin();
    }
};
