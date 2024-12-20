struct tr {
	string key;
	string val;
	int time;
};

class TimeMap {
	vector<tr> v;
public:
    TimeMap() : v{vector<tr>()} {}
    
    void set(string key, string val, int time) {
		int n = v.size();
		int k = 0; 
		for(int b = n/2; b >= 1; b /= 2) {
			while(
				k + b < n &&
				(v[k+b].key < key ||
				(v[k+b].key == key && v[k+b].time <= time))
			) k += b;
		}
		if(k == n) {
			v.push_back(tr{key,val,time});
		}
		else {
			v.insert(v.begin()+k+1, tr{key, val, time});
		}
    }
    
    string get(string key, int time) {  
		int n = v.size();
		int k = 0; 
		for(int b = n/2; b >= 1; b /= 2) {
			while(
				k + b < n &&
				(v[k+b].key < key ||
				(v[k+b].key == key && v[k+b].time <= time))
			) k += b;
		}
		if(v[k].key == key && v[k].time <= time) {
			return v[k].val;
		}
		return "";
    }
};

