class LRUCache {
	int capacity;
	list<int> recentKeys;
	unordered_map<int, int> m;
	unordered_map<int, list<int>::iterator> keyToList;

public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if(m.find(key) == m.end()) {
			return -1;
		}

		recentKeys.erase(keyToList[key]);
		recentKeys.push_back(key);
		keyToList[key] = prev(recentKeys.end());

		return m[key];
    }
    
    void put(int key, int value) {
		// list.size() should be O(1)
        if(m.find(key) == m.end() && recentKeys.size() >= capacity) {
			m.erase(recentKeys.front());
			keyToList.erase(recentKeys.front());
			recentKeys.pop_front();
		}
		else if(m.find(key) != m.end()) {
			recentKeys.erase(keyToList[key]);
		}

		recentKeys.push_back(key);
		keyToList[key] = prev(recentKeys.end());

		m[key] = value;
    }
};

