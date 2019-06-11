class LRUCache {
public:
    unordered_map<int, int> cache = unordered_map<int, int>();
    vector<int> cacheOrder = vector<int>();
    int size = 0;
    int cap = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        /* DEBUG START*/
//        for(int i = 0; i < cacheOrder.size(); i++){
//            cout << cacheOrder[i] << ", ";
//        }
//        cout << "size: " << size << ", capacity" << cap;
//        cout << endl;
        /* DEBUG END*/


        std::unordered_map<int, int>::const_iterator got = cache.find (key);
        if (got == cache.end()){
            return -1;
        } else {
            // Item already exist, update cacheOrder
            int originalRank = -1;

            // iterate to find key
            for(int i = 0; i < cacheOrder.size(); i++){
                if(cacheOrder[i] == key){
                    originalRank = i;
                    break;
                }
            }

            /* update cacheOrder here */
            cacheOrder.erase(cacheOrder.begin() + originalRank);
            cacheOrder.push_back(key);

            return got->second;
        }
    }

    void put(int key, int value) {

        /* DEBUG START*/
//        for(int i = 0; i < cacheOrder.size(); i++){
//            cout << cacheOrder[i] << ", ";
//        }
//        cout << "size: " << size << ", capacity" << cap;
//        cout << endl;
        /* DEBUG END*/


        int target = 0;

        std::unordered_map<int, int>::const_iterator got = cache.find (key);
        if (got == cache.end()){
            target = -1;
        } else {
            target = got->second;
        }

        if(target == -1){
            // if add new item
            if(size == cap){
                int deleteItemIdx = cacheOrder[0];
                cache.erase(deleteItemIdx);
                cacheOrder.erase(cacheOrder.begin()); // delete least recent used
                size--;
            }
            cacheOrder.push_back(key); // add new item
            size++;
        } else {
            // if item already exist, update cacheOrder
            int originalRank = 0;

            for(int i = 0; i < cacheOrder.size(); i++){
                if(cacheOrder[i] == key){
                    originalRank = i;
                    break;
                }
            }

            /* update cacheOrder here */
            cacheOrder.erase(cacheOrder.begin() + originalRank);
            cacheOrder.push_back(key);
        }

        // update cache and other vars
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */