class Solution {
	bool isAllZero(vector<int> &freqs) {
		for(auto freq : freqs) {
			if(freq) return false;
		}
		return true;
	}

public:
    bool checkInclusion(string s1, string s2) {
		vector<int> freqs(26,0);
		for(auto c : s1) {
			freqs[c-'a']++;
		}

		int m = s1.size();
		int n = s2.size();
		if(n < m) return false;

		for(int i = 0; i < m; i++) {
			freqs[s2[i]-'a']--;
		}
		
		for(int i = m; i < n; i++) {
			if(isAllZero(freqs)) return true;
			freqs[s2[i]-'a']--;
			freqs[s2[i-m]-'a']++;
		}

		return isAllZero(freqs);
    }
};

